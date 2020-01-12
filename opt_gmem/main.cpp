#include <sys/time.h>
#include <iostream>
#include <vector>
#include <stdio.h>
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

int main(int argc, char **argv) {
    int                M = 1024;
    int                K = 256;
    int                N = 2048;
    struct timeval     start;
    struct timeval     end;
    matrix_class<char> matrix_A(M, K), matrix_B(K, N), matrix_C(M, N);
    gettimeofday(&start, NULL);
    normal_gemm<char>(M,
                      N,
                      K,
                      matrix_A.matrix_data,
                      matrix_B.matrix_data,
                      matrix_C.matrix_data);
    gettimeofday(&end, NULL);
    std::cout << "normal time cost:" << usec_diff(start, end) << std::endl;
    gettimeofday(&start, NULL);
    lopp_permutation_gemm<char>(M,
                                N,
                                K,
                                matrix_A.matrix_data,
                                matrix_B.matrix_data,
                                matrix_C.matrix_data);
    gettimeofday(&end, NULL);
    std::cout << "lopp_permutation time cost:" << usec_diff(start, end)
              << std::endl;
    gettimeofday(&start, NULL);
    block_gemm<char>(M,
                     N,
                     K,
                     matrix_A.matrix_data,
                     matrix_B.matrix_data,
                     matrix_C.matrix_data);
    gettimeofday(&end, NULL);
    std::cout << "block gemm time cost:" << usec_diff(start, end) << std::endl;
    gettimeofday(&start, NULL);
    lopp_permutation_block_gemm<char>(M,
                     N,
                     K,
                     matrix_A.matrix_data,
                     matrix_B.matrix_data,
                     matrix_C.matrix_data);
    gettimeofday(&end, NULL);
    std::cout << "lopp_permutation block gemm time cost:" << usec_diff(start, end) << std::endl;
    gettimeofday(&start, NULL);
    cache_blocking_gemm<char>(M,
                     N,
                     K,
                     matrix_A.matrix_data,
                     matrix_B.matrix_data,
                     matrix_C.matrix_data);
    gettimeofday(&end, NULL);
    std::cout << "cache blocking gemm time cost:" << usec_diff(start, end) << std::endl;
    gettimeofday(&start, NULL);
    cache_write_gemm<char>(M,
                     N,
                     K,
                     matrix_A.matrix_data,
                     matrix_B.matrix_data,
                     matrix_C.matrix_data);
    gettimeofday(&end, NULL);
    std::cout << "cache write gemm time cost:" << usec_diff(start, end) << std::endl;
    return 0;
}
