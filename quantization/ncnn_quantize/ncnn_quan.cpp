#include "ncnn_quan.h"
#include <algorithm>
#include <cmath>

template <class quan_type_t>
ncnn_quan<quan_type_t>::ncnn_quan(int max_bins,
                                  int min_bins,
                                  int min_quan_bins) {
    m_scalar        = 1.0f;
    m_max_bins      = max_bins;
    m_min_bins      = min_bins;
    m_min_quan_bins = min_quan_bins;
    m_128bins_quan_histogram.resize(m_min_quan_bins);
}

template <class quan_type_t>
void ncnn_quan<quan_type_t>::get_P_complete_histogram(
    std::vector<float> inputs) {
    m_input_size        = inputs.size();
    m_input_abs_max_val = *std::max_element(inputs.begin(), inputs.end());
    m_interval          = m_input_abs_max_val / m_max_bins;
    for (auto elem : inputs) {
        int index = floor(elem / m_interval);
        m_P_complete_histogram[index]++;
    }
}

template <class quan_type_t>
void ncnn_quan<quan_type_t>::get_P_cutted_histogram(
    int cur_bins, std::vector<int>& cur_cutted_histogram) {
    for (int i = cur_bins; i < m_max_bins; ++i) {
        cur_cutted_histogram[cur_bins - 1] += m_P_complete_histogram[i];
    }
}

template <class quan_type_t>
void ncnn_quan<quan_type_t>::get_Q_128bins_histogram(std::vector<float> inputs,
                                                     float cur_scalar,
                                                     float cur_threashold) {
    m_128bins_quan_histogram.clear();
    for (int i = 0; i < m_input_size; i++) {
        if (inputs[i] <= cur_threashold) {
            quan_type_t quan_val = floor(inputs[i] * cur_scalar);
            m_128bins_quan_histogram[quan_val]++;
        } else {
            m_128bins_quan_histogram[m_min_quan_bins - 1]++;
        }
    }
}

template <class quan_type_t>
void ncnn_quan<quan_type_t>::get_Q_expand_histogram(
    int cur_bins, std::vector<quan_type_t>& expand_quan_histogram) {
    float expand_scalar = ((float)cur_bins) / ((float)m_min_quan_bins);
    for (int i = 0; i < cur_bins; i++) {
        const float start      = i * expand_scalar;
        const float end        = start + expand_scalar;
        float       count      = 0;
        const int   left_upper = ceil(start);
        float       left_scale = 0;
        if (left_upper > start) {
            left_scale = left_upper - start;
            if (m_128bins_quan_histogram[left_upper - 1] != 0) {
                count += left_scale;
            }
        }
        const int right_lower = floor(end);
        float     right_scale = 0;
        if (right_lower < end) {
            right_scale = end - right_lower;
            if (m_128bins_quan_histogram[right_lower] != 0) {
                count += right_scale;
            }
        }
        for (int j = left_upper; j < right_lower; j++) {
            if (m_128bins_quan_histogram[j] != 0) {
                count++;
            }
        }
        const float expand_value = m_128bins_quan_histogram[i] / count;
        if (left_upper > start) {
            if (m_128bins_quan_histogram[left_upper - 1] != 0) {
                expand_quan_histogram[left_upper - 1] +=
                    expand_value * left_scale;
            }
        }
        if (right_lower < end) {
            if (m_128bins_quan_histogram[right_lower] != 0) {
                expand_quan_histogram[right_lower] +=
                    expand_value * right_scale;
            }
        }
        for (int j = left_upper; j < right_lower; j++) {
            if (m_128bins_quan_histogram[j] != 0) {
                expand_quan_histogram[j] += expand_value;
            }
        }
    }
}

template <class quan_type_t>
float ncnn_quan<quan_type_t>::calc_kld_histogram(std::vector<float>       P,
                                                 std::vector<quan_type_t> Q) {
    float kld = 0;
    for (int i = 0; i < P.size(); i++) {
        kld += P[i] + log(P[i] / Q[i]);
    }

    return kld;
}

template <class quan_type_t>
void ncnn_quan<quan_type_t>::get_ncnn_table(std::vector<float> inputs) {
    get_P_complete_histogram(inputs);
    float max_kld  = 0.0f;
    int   res_bins = m_min_bins;
    for (int cur_bins = m_min_bins; cur_bins < m_max_bins; cur_bins++) {
        std::vector<int> cur_cutted_histogram(
            m_P_complete_histogram.begin(),
            m_P_complete_histogram.begin() + cur_bins);
        get_P_cutted_histogram(cur_bins, cur_cutted_histogram);
        float cur_threashold = m_interval * cur_bins;
        float cur_scalar     = (m_min_quan_bins - 1) / cur_threashold;
        get_Q_128bins_histogram(inputs, cur_scalar, cur_threashold);
        std::vector<quan_type_t> expand_quan_histogram(cur_bins);
        get_Q_expand_histogram(cur_bins, expand_quan_histogram);
        float cur_kld = 0.0f;
        cur_kld =
            calc_kld_histogram(cur_cutted_histogram, expand_quan_histogram);
        if (cur_kld > max_kld) {
            res_bins = cur_bins;
        }
    }
    m_scalar = (m_interval * res_bins) / (m_input_abs_max_val);
}

template <class quan_type_t>
void ncnn_quan<quan_type_t>::inference_quan(std::vector<float>        inputs,
                                            std::vector<quan_type_t>& outputs,
                                            int                       bias) {
    get_ncnn_table(inputs);
    // output = input * m_scalar + bias
    for (int i = 0; i < inputs.size(); i++) {
        outputs[i] = inputs[i] * m_scalar + bias;
    }
}
