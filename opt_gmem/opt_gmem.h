#ifndef TEST_SET_H
#define TEST_SET_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
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

#if 1
template <typename type_t>
void lopp_permutation_block_gemm(int                 M,
                                 int                 N,
                                 int                 K,
                                 std::vector<type_t> A,
                                 std::vector<type_t> B,
                                 std::vector<type_t> C) {
    type_t amk[16][16];
    for (int m = 0; m < M; m= m + 8) {
        for (int k = 0; k < K; k+=8) {
            amk[0][0] = A[m * K + k];
            amk[0][1] = A[m * K + k + 1];
            amk[0][2] = A[m * K + k + 2];
            amk[0][3] = A[m * K + k + 3];
            amk[0][4] = A[m * K + k + 4];
            amk[0][5] = A[m * K + k + 5];
            amk[0][6] = A[m * K + k + 6];
            amk[0][7] = A[m * K + k + 7];
            amk[1][0] = A[(m + 0) * K + k];
            amk[1][1] = A[(m + 1) * K + k + 1];
            amk[1][2] = A[(m + 1) * K + k + 2];
            amk[1][3] = A[(m + 1) * K + k + 3];
            amk[1][4] = A[(m + 1) * K + k + 4];
            amk[1][5] = A[(m + 1) * K + k + 5];
            amk[1][6] = A[(m + 1) * K + k + 6];
            amk[1][7] = A[(m + 1) * K + k + 7];
            amk[2][0] = A[(m + 2) * K + k];
            amk[2][1] = A[(m + 2) * K + k + 1];
            amk[2][2] = A[(m + 2) * K + k + 2];
            amk[2][3] = A[(m + 2) * K + k + 3];
            amk[2][4] = A[(m + 2) * K + k + 4];
            amk[2][5] = A[(m + 2) * K + k + 5];
            amk[2][6] = A[(m + 2) * K + k + 6];
            amk[2][7] = A[(m + 2) * K + k + 7];
            amk[3][0] = A[(m + 3) * K + k];
            amk[3][1] = A[(m + 3) * K + k + 1];
            amk[3][2] = A[(m + 3) * K + k + 2];
            amk[3][3] = A[(m + 3) * K + k + 3];
            amk[3][4] = A[(m + 3) * K + k + 4];
            amk[3][5] = A[(m + 3) * K + k + 5];
            amk[3][6] = A[(m + 3) * K + k + 6];
            amk[3][7] = A[(m + 3) * K + k + 7];
            amk[4][0] = A[(m + 4) * K + k];
            amk[4][1] = A[(m + 4) * K + k + 1];
            amk[4][2] = A[(m + 4) * K + k + 2];
            amk[4][3] = A[(m + 4) * K + k + 3];
            amk[4][4] = A[(m + 4) * K + k + 4];
            amk[4][5] = A[(m + 4) * K + k + 5];
            amk[4][6] = A[(m + 4) * K + k + 6];
            amk[4][7] = A[(m + 4) * K + k + 7];
            amk[5][0] = A[(m + 5) * K + k];
            amk[5][1] = A[(m + 5) * K + k + 1];
            amk[5][2] = A[(m + 5) * K + k + 2];
            amk[5][3] = A[(m + 5) * K + k + 3];
            amk[5][4] = A[(m + 5) * K + k + 4];
            amk[5][5] = A[(m + 5) * K + k + 5];
            amk[5][6] = A[(m + 5) * K + k + 6];
            amk[5][7] = A[(m + 5) * K + k + 7];
            amk[6][0] = A[(m + 6) * K + k];
            amk[6][1] = A[(m + 6) * K + k + 1];
            amk[6][2] = A[(m + 6) * K + k + 2];
            amk[6][3] = A[(m + 6) * K + k + 3];
            amk[6][4] = A[(m + 6) * K + k + 4];
            amk[6][5] = A[(m + 6) * K + k + 5];
            amk[6][6] = A[(m + 6) * K + k + 6];
            amk[6][7] = A[(m + 6) * K + k + 7];
            amk[7][0] = A[(m + 7) * K + k];
            amk[7][1] = A[(m + 7) * K + k + 1];
            amk[7][2] = A[(m + 7) * K + k + 2];
            amk[7][3] = A[(m + 7) * K + k + 3];
            amk[7][4] = A[(m + 7) * K + k + 4];
            amk[7][5] = A[(m + 7) * K + k + 5];
            amk[7][6] = A[(m + 7) * K + k + 6];
            amk[7][7] = A[(m + 7) * K + k + 7];
            for (int n = 0; n < N; n = n + 8) {
                C[m * K + n + 0] += amk[0][0] * B[(k + 0) * N + n]; 
                C[m * K + n + 1] += amk[0][0] * B[k * N + n + 1]; 
                C[m * K + n + 2] += amk[0][0] * B[k * N + n + 2]; 
                C[m * K + n + 3] += amk[0][0] * B[k * N + n + 3]; 
                C[m * K + n + 4] += amk[0][0] * B[k * N + n + 4]; 
                C[m * K + n + 5] += amk[0][0] * B[k * N + n + 5]; 
                C[m * K + n + 6] += amk[0][0] * B[k * N + n + 6]; 
                C[m * K + n + 7] += amk[0][0] * B[k * N + n + 7]; 
                C[m * K + n + 0] += amk[0][1] * B[(k + 1) * N + n]; 
                C[m * K + n + 1] += amk[0][1] * B[(k + 1) * N + n + 1]; 
                C[m * K + n + 2] += amk[0][1] * B[(k + 1) * N + n + 2]; 
                C[m * K + n + 3] += amk[0][1] * B[(k + 1) * N + n + 3]; 
                C[m * K + n + 4] += amk[0][1] * B[(k + 1) * N + n + 4]; 
                C[m * K + n + 5] += amk[0][1] * B[(k + 1) * N + n + 5]; 
                C[m * K + n + 6] += amk[0][1] * B[(k + 1) * N + n + 6]; 
                C[m * K + n + 7] += amk[0][1] * B[(k + 1) * N + n + 7]; 
                C[m * K + n + 0] += amk[0][2] * B[(k + 2) * N + n]; 
                C[m * K + n + 1] += amk[0][2] * B[(k + 2) * N + n + 1]; 
                C[m * K + n + 2] += amk[0][2] * B[(k + 2) * N + n + 2]; 
                C[m * K + n + 3] += amk[0][2] * B[(k + 2) * N + n + 3]; 
                C[m * K + n + 4] += amk[0][2] * B[(k + 2) * N + n + 4]; 
                C[m * K + n + 5] += amk[0][2] * B[(k + 2) * N + n + 5]; 
                C[m * K + n + 6] += amk[0][2] * B[(k + 2) * N + n + 6]; 
                C[m * K + n + 7] += amk[0][2] * B[(k + 2) * N + n + 7]; 
                C[m * K + n + 0] += amk[0][3] * B[(k + 3) * N + n]; 
                C[m * K + n + 1] += amk[0][3] * B[(k + 3) * N + n + 1]; 
                C[m * K + n + 2] += amk[0][3] * B[(k + 3) * N + n + 2]; 
                C[m * K + n + 3] += amk[0][3] * B[(k + 3) * N + n + 3]; 
                C[m * K + n + 4] += amk[0][4] * B[(k + 4) * N + n + 4]; 
                C[m * K + n + 5] += amk[0][4] * B[(k + 4) * N + n + 5]; 
                C[m * K + n + 6] += amk[0][4] * B[(k + 4) * N + n + 6]; 
                C[m * K + n + 7] += amk[0][4] * B[(k + 4) * N + n + 7]; 
                C[(m + 1) * K + n + 0] += amk[1][0] * B[k * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][0] * B[k * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][0] * B[k * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][0] * B[k * N + n + 3]; 
                C[(m + 1) * K + n + 4] += amk[1][0] * B[k * N + n + 4]; 
                C[(m + 1) * K + n + 5] += amk[1][0] * B[k * N + n + 5]; 
                C[(m + 1) * K + n + 6] += amk[1][0] * B[k * N + n + 6]; 
                C[(m + 1) * K + n + 7] += amk[1][0] * B[k * N + n + 7]; 
                C[(m + 1) * K + n + 0] += amk[1][1] * B[(k + 1) * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][1] * B[(k + 1) * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][1] * B[(k + 1) * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][1] * B[(k + 1) * N + n + 3]; 
                C[(m + 1) * K + n + 4] += amk[1][1] * B[(k + 1) * N + n + 4]; 
                C[(m + 1) * K + n + 5] += amk[1][1] * B[(k + 1) * N + n + 5]; 
                C[(m + 1) * K + n + 6] += amk[1][1] * B[(k + 1) * N + n + 6]; 
                C[(m + 1) * K + n + 7] += amk[1][1] * B[(k + 1) * N + n + 7]; 
                C[(m + 1) * K + n + 0] += amk[1][2] * B[(k + 2) * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][2] * B[(k + 2) * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][2] * B[(k + 2) * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][2] * B[(k + 2) * N + n +3]; 
                C[(m + 1) * K + n + 4] += amk[1][2] * B[(k + 2) * N + n + 4]; 
                C[(m + 1) * K + n + 5] += amk[1][2] * B[(k + 2) * N + n + 5]; 
                C[(m + 1) * K + n + 6] += amk[1][2] * B[(k + 2) * N + n + 6]; 
                C[(m + 1) * K + n + 7] += amk[1][2] * B[(k + 2) * N + n + 7]; 
                C[(m + 1) * K + n + 0] += amk[1][3] * B[(k + 3) * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][3] * B[(k + 3) * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][3] * B[(k + 3) * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][3] * B[(k + 3) * N + n +3]; 
                C[(m + 1) * K + n + 4] += amk[1][3] * B[(k + 3) * N + n + 4]; 
                C[(m + 1) * K + n + 5] += amk[1][3] * B[(k + 3) * N + n + 5]; 
                C[(m + 1) * K + n + 6] += amk[1][3] * B[(k + 3) * N + n + 6]; 
                C[(m + 1) * K + n + 7] += amk[1][3] * B[(k + 3) * N + n + 7]; 
                C[(m + 2) * K + n + 0] += amk[2][0] * B[k * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][0] * B[k * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][0] * B[k * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][0] * B[k * N + n + 3]; 
                C[(m + 2) * K + n + 4] += amk[2][0] * B[(k + 0) * N + n + 4]; 
                C[(m + 2) * K + n + 5] += amk[2][0] * B[(k + 0) * N + n + 5]; 
                C[(m + 2) * K + n + 6] += amk[2][0] * B[(k + 0) * N + n + 6]; 
                C[(m + 2) * K + n + 7] += amk[2][0] * B[(k + 0) * N + n + 7]; 
                C[(m + 2) * K + n + 0] += amk[2][1] * B[(k + 1) * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][1] * B[(k + 1) * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][1] * B[(k + 1) * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][1] * B[(k + 1) * N + n +3]; 
                C[(m + 2) * K + n + 4] += amk[2][1] * B[(k + 1) * N + n + 4]; 
                C[(m + 2) * K + n + 5] += amk[2][1] * B[(k + 1) * N + n + 5]; 
                C[(m + 2) * K + n + 6] += amk[2][1] * B[(k + 1) * N + n + 6]; 
                C[(m + 2) * K + n + 7] += amk[2][1] * B[(k + 1) * N + n + 7]; 
                C[(m + 2) * K + n + 0] += amk[2][2] * B[(k + 2) * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][2] * B[(k + 2) * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][2] * B[(k + 2) * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][2] * B[(k + 2) * N + n + 3]; 
                C[(m + 2) * K + n + 4] += amk[2][2] * B[(k + 2) * N + n + 4]; 
                C[(m + 2) * K + n + 5] += amk[2][2] * B[(k + 2) * N + n + 5]; 
                C[(m + 2) * K + n + 6] += amk[2][2] * B[(k + 2) * N + n + 6]; 
                C[(m + 2) * K + n + 7] += amk[2][2] * B[(k + 2) * N + n + 7]; 
                C[(m + 2) * K + n + 0] += amk[2][3] * B[(k + 3) * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][3] * B[(k + 3) * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][3] * B[(k + 3) * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][3] * B[(k + 3) * N + n + 3]; 
                C[(m + 2) * K + n + 4] += amk[2][3] * B[(k + 3) * N + n + 4]; 
                C[(m + 2) * K + n + 5] += amk[2][3] * B[(k + 3) * N + n + 5]; 
                C[(m + 2) * K + n + 6] += amk[2][3] * B[(k + 3) * N + n + 6]; 
                C[(m + 2) * K + n + 7] += amk[2][3] * B[(k + 3) * N + n + 7]; 
                C[(m + 3) * K + n + 0] += amk[3][0] * B[k * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][0] * B[k * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][0] * B[k * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][0] * B[k * N + n + 3]; 
                C[(m + 3) * K + n + 4] += amk[3][3] * B[(k + 0) * N + n + 4]; 
                C[(m + 3) * K + n + 5] += amk[3][3] * B[(k + 0) * N + n + 5]; 
                C[(m + 3) * K + n + 6] += amk[3][3] * B[(k + 0) * N + n + 6]; 
                C[(m + 3) * K + n + 7] += amk[3][3] * B[(k + 0) * N + n + 7]; 
                C[(m + 3) * K + n + 0] += amk[3][1] * B[(k + 1) * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][1] * B[(k + 1) * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][1] * B[(k + 1) * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][1] * B[(k + 1) * N + n +3]; 
                C[(m + 3) * K + n + 4] += amk[3][1] * B[(k + 1) * N + n + 4]; 
                C[(m + 3) * K + n + 5] += amk[3][1] * B[(k + 1) * N + n + 5]; 
                C[(m + 3) * K + n + 6] += amk[3][1] * B[(k + 1) * N + n + 6]; 
                C[(m + 3) * K + n + 7] += amk[3][1] * B[(k + 1) * N + n + 7]; 
                C[(m + 3) * K + n + 0] += amk[3][2] * B[(k + 2) * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][2] * B[(k + 2) * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][2] * B[(k + 2) * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][2] * B[(k + 2) * N + n +3]; 
                C[(m + 3) * K + n + 4] += amk[3][2] * B[(k + 2) * N + n + 4]; 
                C[(m + 3) * K + n + 5] += amk[3][2] * B[(k + 2) * N + n + 5]; 
                C[(m + 3) * K + n + 6] += amk[3][2] * B[(k + 2) * N + n + 6]; 
                C[(m + 3) * K + n + 7] += amk[3][2] * B[(k + 2) * N + n + 7]; 
                C[(m + 3) * K + n + 0] += amk[3][3] * B[(k + 3) * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][3] * B[(k + 3) * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][3] * B[(k + 3) * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][3] * B[(k + 3) * N + n +3]; 
                C[(m + 3) * K + n + 4] += amk[3][3] * B[(k + 3) * N + n + 4]; 
                C[(m + 3) * K + n + 5] += amk[3][3] * B[(k + 3) * N + n + 5]; 
                C[(m + 3) * K + n + 6] += amk[3][3] * B[(k + 3) * N + n + 6]; 
                C[(m + 3) * K + n + 7] += amk[3][3] * B[(k + 3) * N + n + 7]; 
            }
        }
    }
}
#else
template <typename type_t>
void lopp_permutation_block_gemm(int                 M,
                                 int                 N,
                                 int                 K,
                                 std::vector<type_t> A,
                                 std::vector<type_t> B,
                                 std::vector<type_t> C) {
    type_t amk[4][4];
    for (int m = 0; m < M; m= m + 4) {
        for (int k = 0; k < K; k+=4) {
            amk[0][0] = A[m * K + k];
            amk[0][1] = A[m * K + k + 1];
            amk[0][2] = A[m * K + k + 2];
            amk[0][3] = A[m * K + k + 3];
            amk[1][0] = A[(m + 0) * K + k];
            amk[1][1] = A[(m + 1) * K + k + 1];
            amk[1][2] = A[(m + 1) * K + k + 2];
            amk[1][3] = A[(m + 1) * K + k + 3];
            amk[2][0] = A[(m + 2) * K + k];
            amk[2][1] = A[(m + 2) * K + k + 1];
            amk[2][2] = A[(m + 2) * K + k + 2];
            amk[2][3] = A[(m + 2) * K + k + 3];
            amk[3][0] = A[(m + 3) * K + k];
            amk[3][1] = A[(m + 3) * K + k + 1];
            amk[3][2] = A[(m + 3) * K + k + 2];
            amk[3][3] = A[(m + 3) * K + k + 3];
            for (int n = 0; n < N; n = n + 4) {
                C[m * K + n + 0] += amk[0][0] * B[(k + 0) * N + n]; 
                C[m * K + n + 1] += amk[0][0] * B[k * N + n + 1]; 
                C[m * K + n + 2] += amk[0][0] * B[k * N + n + 2]; 
                C[m * K + n + 3] += amk[0][0] * B[k * N + n + 3]; 
                C[m * K + n + 0] += amk[0][1] * B[(k + 1) * N + n]; 
                C[m * K + n + 1] += amk[0][1] * B[(k + 1) * N + n + 1]; 
                C[m * K + n + 2] += amk[0][1] * B[(k + 1) * N + n + 2]; 
                C[m * K + n + 3] += amk[0][1] * B[(k + 1) * N + n + 3]; 
                C[m * K + n + 0] += amk[0][2] * B[(k + 2) * N + n]; 
                C[m * K + n + 1] += amk[0][2] * B[(k + 2) * N + n + 1]; 
                C[m * K + n + 2] += amk[0][2] * B[(k + 2) * N + n + 2]; 
                C[m * K + n + 3] += amk[0][2] * B[(k + 2) * N + n + 3]; 
                C[m * K + n + 0] += amk[0][3] * B[(k + 3) * N + n]; 
                C[m * K + n + 1] += amk[0][3] * B[(k + 3) * N + n + 1]; 
                C[m * K + n + 2] += amk[0][3] * B[(k + 3) * N + n + 2]; 
                C[m * K + n + 3] += amk[0][3] * B[(k + 3) * N + n + 3]; 
                C[(m + 1) * K + n + 0] += amk[1][0] * B[k * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][0] * B[k * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][0] * B[k * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][0] * B[k * N + n + 3]; 
                C[(m + 1) * K + n + 0] += amk[1][1] * B[(k + 1) * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][1] * B[(k + 1) * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][1] * B[(k + 1) * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][1] * B[(k + 1) * N + n +3]; 
                C[(m + 1) * K + n + 0] += amk[1][2] * B[(k + 2) * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][2] * B[(k + 2) * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][2] * B[(k + 2) * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][2] * B[(k + 2) * N + n +3]; 
                C[(m + 1) * K + n + 0] += amk[1][3] * B[(k + 3) * N + n]; 
                C[(m + 1) * K + n + 1] += amk[1][3] * B[(k + 3) * N + n + 1]; 
                C[(m + 1) * K + n + 2] += amk[1][3] * B[(k + 3) * N + n + 2]; 
                C[(m + 1) * K + n + 3] += amk[1][3] * B[(k + 3) * N + n +3]; 
                C[(m + 2) * K + n + 0] += amk[2][0] * B[k * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][0] * B[k * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][0] * B[k * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][0] * B[k * N + n + 3]; 
                C[(m + 2) * K + n + 0] += amk[2][1] * B[(k + 1) * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][1] * B[(k + 1) * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][1] * B[(k + 1) * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][1] * B[(k + 1) * N + n +3]; 
                C[(m + 2) * K + n + 0] += amk[2][2] * B[(k + 2) * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][2] * B[(k + 2) * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][2] * B[(k + 2) * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][2] * B[(k + 2) * N + n +3]; 
                C[(m + 2) * K + n + 0] += amk[2][3] * B[(k + 3) * N + n]; 
                C[(m + 2) * K + n + 1] += amk[2][3] * B[(k + 3) * N + n + 1]; 
                C[(m + 2) * K + n + 2] += amk[2][3] * B[(k + 3) * N + n + 2]; 
                C[(m + 2) * K + n + 3] += amk[2][3] * B[(k + 3) * N + n +3]; 
                C[(m + 3) * K + n + 0] += amk[3][0] * B[k * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][0] * B[k * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][0] * B[k * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][0] * B[k * N + n + 3]; 
                C[(m + 3) * K + n + 0] += amk[3][1] * B[(k + 1) * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][1] * B[(k + 1) * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][1] * B[(k + 1) * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][1] * B[(k + 1) * N + n +3]; 
                C[(m + 3) * K + n + 0] += amk[3][2] * B[(k + 2) * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][2] * B[(k + 2) * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][2] * B[(k + 2) * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][2] * B[(k + 2) * N + n +3]; 
                C[(m + 3) * K + n + 0] += amk[3][3] * B[(k + 3) * N + n]; 
                C[(m + 3) * K + n + 1] += amk[3][3] * B[(k + 3) * N + n + 1]; 
                C[(m + 3) * K + n + 2] += amk[3][3] * B[(k + 3) * N + n + 2]; 
                C[(m + 3) * K + n + 3] += amk[3][3] * B[(k + 3) * N + n +3]; 
            }
        }
    }
}
#endif

#define CACHE_BLOCKING_SIZE (64)
#if 0
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
#endif

template <typename type_t>
void cache_blocking_gemm_block(
    int M, int N, int K, type_t *A, type_t *B, type_t *C) {
    type_t amk[4][4];
    for (int m = 0; m < CACHE_BLOCKING_SIZE; m= m + 4) {
        for (int k = 0; k < CACHE_BLOCKING_SIZE; k+=4) {
            amk[0][0] = A[m * K + k];
            amk[0][1] = A[m * K + k + 1];
            amk[0][2] = A[m * K + k + 2];
            amk[0][3] = A[m * K + k + 3];
            amk[1][0] = A[(m + 0) * K + k];
            amk[1][1] = A[(m + 1) * K + k + 1];
            amk[1][2] = A[(m + 2) * K + k + 2];
            amk[1][3] = A[(m + 3) * K + k + 3];
            amk[2][0] = A[(m + 0) * K + k];
            amk[2][1] = A[(m + 1) * K + k + 1];
            amk[2][2] = A[(m + 2) * K + k + 2];
            amk[2][3] = A[(m + 3) * K + k + 3];
            amk[3][0] = A[(m + 0) * K + k];
            amk[3][1] = A[(m + 1) * K + k + 1];
            amk[3][2] = A[(m + 2) * K + k + 2];
            amk[3][3] = A[(m + 3) * K + k + 3];
            for (int n = 0; n < CACHE_BLOCKING_SIZE; n = n + 4) {
                C[m * n + n] += amk[0][0] * B[k * N + n]; 
                C[m * n + n + 1] += amk[0][0] * B[k * N + n + 1]; 
                C[m * n + n + 2] += amk[0][0] * B[k * N + n + 2]; 
                C[m * n + n + 3] += amk[0][0] * B[k * N + n + 3]; 
                C[(m + 1) * n + n + 0] += amk[1][0] * B[k * N + n]; 
                C[(m + 1) * n + n + 1] += amk[1][0] * B[k * N + n + 1]; 
                C[(m + 1) * n + n + 2] += amk[1][0] * B[k * N + n + 2]; 
                C[(m + 1) * n + n + 3] += amk[1][0] * B[k * N + n + 3]; 
                C[(m + 2) * n + n + 0] += amk[2][0] * B[k * N + n]; 
                C[(m + 2) * n + n + 1] += amk[2][0] * B[k * N + n + 1]; 
                C[(m + 2) * n + n + 2] += amk[2][0] * B[k * N + n + 2]; 
                C[(m + 2) * n + n + 3] += amk[2][0] * B[k * N + n + 3]; 
                C[(m + 3) * n + n + 0] += amk[3][0] * B[k * N + n]; 
                C[(m + 3) * n + n + 1] += amk[3][0] * B[k * N + n + 1]; 
                C[(m + 3) * n + n + 2] += amk[3][0] * B[k * N + n + 2]; 
                C[(m + 3) * n + n + 3] += amk[3][0] * B[k * N + n + 3]; 
            }
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
            // C[i * N + j] = cij;                     /* C[i][j] = cij */
            temp[j] = cij;
        }
        memcpy(&C[i * N], temp, N);
    }
}

template <typename type_t>
void openmp_gemm(int                 M,
                 int                 N,
                 int                 K,
                 std::vector<type_t> A,
                 std::vector<type_t> B,
                 std::vector<type_t> C) {
    for (int i = 0; i < M; ++i) {
        #pragma omp parallel for
        for (int j = 0; j < N; ++j) {
            type_t cij = C[i * N + j]; /* cij = C[i][j] */
            for (int k = 0; k < K; k++)
                cij += A[i * K + k] * B[k * N + j]; /* cij += A[i][k]*B[k][j] */
            C[i * N + j] = cij;                     /* C[i][j] = cij */
        }
    }
}

#endif /* TEST_SET_H */
