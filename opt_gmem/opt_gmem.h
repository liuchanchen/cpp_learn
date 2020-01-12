#ifndef TEST_SET_H
#define TEST_SET_H
#include <stdint.h>
#include <vector>

template <typename type_t>
void normal_gemm(int                 M,
                 int                 N,
                 int                 K,
                 std::vector<type_t> A,
                 std::vector<type_t> B,
                 std::vector<type_t> C) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            type_t cij = C[i * N + j]; /* cij = C[i][j] */
            for (int k = 0; k < K; k++)
                cij += A[i * K + k] * B[k * N + j]; /* cij += A[i][k]*B[k][j] */
            C[i * N + j] = cij;                     /* C[i][j] = cij */
        }
    }
}

template <typename type_t>
void lopp_permutation_gemm(int                 M,
                           int                 N,
                           int                 K,
                           std::vector<type_t> A,
                           std::vector<type_t> B,
                           std::vector<type_t> C) {
    for (int m = 0; m < M; ++m) {
        for (int k = 0; k < K; k++) {
            type_t amk       = A[m * K + k];
            int    row_len   = k * N;
            int    a_row_len = m * N;
            for (int n = 0; n < N; ++n) {
                C[a_row_len + n] +=
                    amk * B[row_len + n]; /* cmn += A[m][k]*B[k][n] */
            }
        }
    }
}
#endif /* TEST_SET_H */
