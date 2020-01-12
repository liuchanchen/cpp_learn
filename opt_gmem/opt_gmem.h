#ifndef TEST_SET_H
#define TEST_SET_H
#include <stdint.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

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

template <typename type_t>
void block_gemm(int                 M,
                int                 N,
                int                 K,
                std::vector<type_t> A,
                std::vector<type_t> B,
                std::vector<type_t> C) {
    for (int i = 0; i < M; i = i + 1) {
        for (int j = 0; j < N; j = j + 1) {
            type_t cij = C[i * N + j]; /* cij = C[i][j] */
            for (int k = 0; k < K; k = k + 4) {
                cij += A[i * K + k] * B[k * N + j]; /* cij += A[i][k]*B[k][j] */
                cij += A[i * K + k + 1] *
                       B[(k + 1) * N + j]; /* cij += A[i][k]*B[k][j] */
                cij += A[i * K + k + 2] *
                       B[(k + 2) * N + j]; /* cij += A[i][k]*B[k][j] */
                cij += A[i * K + k + 3] *
                       B[(k + 3) * N + j]; /* cij += A[i][k]*B[k][j] */
                // cij += A[i * K + k + 4] *
                //       B[(k + 4) * N + j]; /* cij += A[i][k]*B[k][j] */
                // cij += A[i * K + k + 5] *
                //       B[(k + 5) * N + j]; /* cij += A[i][k]*B[k][j] */
                // cij += A[i * K + k + 6] *
                //       B[(k + 6) * N + j]; /* cij += A[i][k]*B[k][j] */
                // cij += A[i * K + k + 7] *
                //       B[(k + 7) * N + j]; /* cij += A[i][k]*B[k][j] */
            }
            C[i * N + j] = cij; /* C[i][j] = cij */
        }
    }
}

template <typename type_t>
void lopp_permutation_block_gemm(int                 M,
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
            for (int n = 0; n < N; n = n + 4) {
                C[a_row_len + n] +=
                    amk * B[row_len + n]; /* cmn += A[m][k]*B[k][n] */
                C[a_row_len + n + 1] +=
                    amk * B[row_len + n + 1]; /* cmn += A[m][k]*B[k][n] */
                C[a_row_len + n + 2] +=
                    amk * B[row_len + n + 2]; /* cmn += A[m][k]*B[k][n] */
                C[a_row_len + n + 3] +=
                    amk * B[row_len + n + 3]; /* cmn += A[m][k]*B[k][n] */
            }
        }
    }
}

#define CACHE_BLOCKING_SIZE (64)
template <typename type_t>
void cache_blocking_gemm_block(
    int M, int N, int K, type_t *A, type_t *B, type_t *C) {
    for (int i = 0; i < CACHE_BLOCKING_SIZE; i = i + 1) {
        for (int j = 0; j < CACHE_BLOCKING_SIZE; j = j + 1) {
            type_t cij = C[i * N + j]; /* cij = C[i][j] */
            for (int k = 0; k < CACHE_BLOCKING_SIZE; k = k + 4) {
                cij += A[i * K + k] * B[k * N + j]; /* cij += A[i][k]*B[k][j] */
                cij += A[i * K + k + 1] *
                       B[(k + 1) * N + j]; /* cij += A[i][k]*B[k][j] */
                cij += A[i * K + k + 2] *
                       B[(k + 2) * N + j]; /* cij += A[i][k]*B[k][j] */
                cij += A[i * K + k + 3] *
                       B[(k + 3) * N + j]; /* cij += A[i][k]*B[k][j] */
            }
            C[i * N + j] = cij; /* C[i][j] = cij */
        }
    }
}

template <typename type_t>
void cache_blocking_gemm(int                 M,
                         int                 N,
                         int                 K,
                         std::vector<type_t> A,
                         std::vector<type_t> B,
                         std::vector<type_t> C) {
    for (int m = 0; m < M; m = m + CACHE_BLOCKING_SIZE) {
        for (int n = 0; n < N; n = n + CACHE_BLOCKING_SIZE) {
            for (int k = 0; k < K; k = k + CACHE_BLOCKING_SIZE) {
                cache_blocking_gemm_block(M,
                                          N,
                                          K,
                                          &A[CACHE_BLOCKING_SIZE * m + k],
                                          &B[CACHE_BLOCKING_SIZE * k + n],
                                          &C[CACHE_BLOCKING_SIZE * m + n]);
            }
        }
    }
}

template <typename type_t>
void cache_write_gemm(int                 M,
                 int                 N,
                 int                 K,
                 std::vector<type_t> A,
                 std::vector<type_t> B,
                 std::vector<type_t> C) {
    type_t temp[N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            type_t cij = C[i * N + j]; /* cij = C[i][j] */
            for (int k = 0; k < K; k++)
                cij += A[i * K + k] * B[k * N + j]; /* cij += A[i][k]*B[k][j] */
            //C[i * N + j] = cij;                     /* C[i][j] = cij */
            temp[j] = cij;
        }
        memcpy(&C[i * N], temp, N);
    }
}

#endif /* TEST_SET_H */
