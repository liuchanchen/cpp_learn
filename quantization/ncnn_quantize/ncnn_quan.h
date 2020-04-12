#ifndef NCNN_QUAN_H
#define NCNN_QUAN_H

#include <iostream>
#include <vector>

// all inputs should be postive numbers
template <class quan_type_t>
class ncnn_quan {
   public:
    ncnn_quan(int max_bin = 2048, int min_bin = 2048, int min_quan_bins = 128);
    ~ncnn_quan();
    void get_ncnn_table(std::vector<float> inputs);
    void inference_quan(std::vector<float>        inputs,
                        std::vector<quan_type_t>& outputs,
                        int                       bias = 0);

   private:
    void get_P_complete_histogram(std::vector<float> inputs);
    void get_P_cutted_histogram(int               cur_bins,
                                std::vector<int>& cur_cutted_histogram);
    void get_Q_128bins_histogram(std::vector<float> inputs,
                                 float              cur_scalar,
                                 float              cur_threashold);
    void get_Q_expand_histogram(
        int cur_bins, std::vector<quan_type_t>& expand_quan_histogram);
    float calc_kld_histogram(std::vector<float> P, std::vector<quan_type_t> Q);
    float m_scalar;
    int   m_max_bins;
    int   m_min_bins;
    int   m_input_size;
    float m_input_abs_max_val;
    float m_interval;
    int   m_min_quan_bins;
    std::vector<int> m_P_complete_histogram;
    std::vector<int> m_128bins_quan_histogram;
};

#endif /* NCNN_QUAN_H */
