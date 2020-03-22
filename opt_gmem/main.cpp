#include <stdio.h>
#include <sys/time.h>
#include <functional>
#include <iostream>
#include <vector>
#include "opt_gmem.h"

template <typename type_t>
static int generate_matrix(std::vector<type_t> &matrix, int row, int column) {
    for (int i = 0; i < row * column; i++) {
        type_t val = rand() % 255;
        matrix.push_back(val);
    }

    return 0;
}

template <typename type_t>
class matrix_class {
   public:
    matrix_class(int, int);
    int                 row;
    int                 column;
    std::vector<type_t> matrix_data;
};

template <typename type_t>
matrix_class<type_t>::matrix_class(int row, int column) {
    row    = row;
    column = column;
    generate_matrix(matrix_data, row, column);
}

static inline int64_t usec_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000LL +
           (end.tv_usec - start.tv_usec);
}

template <typename type_t>
void test_func_model(int                                      M,
                     int                                      K,
                     int                                      N,
                     std::function<void(int,
                                        int,
                                        int,
                                        std::vector<type_t>,
                                        std::vector<type_t>,
                                        std::vector<type_t>)> cb,
                     std::string                              comment,
                     int                                      trials = 1) {
    struct timeval       start;
    struct timeval       end;
    std::vector<int64_t> time_cost_vec;
    for (int i = 0; i < trials; ++i) {
        matrix_class<char> matrix_A(M, K), matrix_B(K, N), matrix_C(M, N);
        gettimeofday(&start, NULL);
        cb(M,
           N,
           K,
           matrix_A.matrix_data,
           matrix_B.matrix_data,
           matrix_C.matrix_data);
        gettimeofday(&end, NULL);
        time_cost_vec.push_back(usec_diff(start, end));
    }
    int64_t time_cost_sum = 0;
    for (auto time_cost : time_cost_vec) {
        time_cost_sum += time_cost;
    }
    std::cout << comment
              << " time cost:" << time_cost_sum / time_cost_vec.size()
              << std::endl;
}

int main(int argc, char **argv) {
    int M      = 1024;
    int K      = 1024;
    int N      = 1024;
    int trials = 8;
    test_func_model<char>(M, K, N, normal_gemm<char>, "normal", trials);
   // test_func_model<char>(
   //     M, K, N, lopp_permutation_gemm<char>, "lopp_permutation_gemm", trials);
   // test_func_model<char>(M, K, N, block_gemm<char>, "block_gemm", trials);
    test_func_model<char>(M,
                          K,
                          N,
                          lopp_permutation_block_gemm<char>,
                          "lopp_permutation_block_gemm",
                          trials);
    //test_func_model<char>(
    //    M, K, N, cache_blocking_gemm<char>, "cache_blocking_gemm", trials);
    //test_func_model<char>(
    //    M, K, N, cache_write_gemm<char>, "cache_write_gemm", trials);
    //test_func_model<char>(M, K, N, openmp_gemm<char>, "openmp_gemm", trials);
    test_func_model<char>(
        M, K, N, tile_2x2_gemm<char>, "tile_2x2_gemm", trials);

    return 0;
}
