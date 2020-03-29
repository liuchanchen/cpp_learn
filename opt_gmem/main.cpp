#include <stdio.h>
#include <sys/time.h>

#include <functional>
#include <iostream>
#include <vector>

#include "opt_gmem.h"

template <typename type_t>
static int generate_matrix(std::vector<type_t>& matrix, int row, int column) {
  for (int i = 0; i < row * column; i++) {
    //type_t val = rand() % 255;
    type_t val = i % 255;
    matrix.push_back(val);
  }

  return 0;
}

template <typename type_t>
class matrix_class {
 public:
  matrix_class(int, int);
  int m_row;
  int m_column;
  std::vector<type_t> matrix_data;
};

template <typename type_t>
matrix_class<type_t>::matrix_class(int row, int column) {
  m_row = row;
  m_column = column;
  generate_matrix(matrix_data, row, column);
}

static inline int64_t usec_diff(struct timeval start, struct timeval end) {
  return (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
}

template <typename type_t>
void ref_cal(int M, int N, int K, std::vector<type_t> A, std::vector<type_t> B,
             std::vector<type_t>& C) {
  for (int m = 0; m < M; ++m) {
    for (int k = 0; k < K; k++) {
      type_t amk = A[m * K + k];
      int row_len = k * N;
      int a_row_len = m * N;
      for (int n = 0; n < N; ++n) {
        C[a_row_len + n] += amk * B[row_len + n]; /* cmn += A[m][k]*B[k][n] */
      }
    }
  }
}

template <typename type_t>
static bool check_result(std::vector<type_t> res, int M, int N, int K, std::vector<type_t> A,
                         std::vector<type_t> B) {
  matrix_class<type_t> C_ref(M, N);
  memset(&C_ref.matrix_data[0], 0x0, C_ref.matrix_data.size());
  ref_cal(M, N, K, A, B, C_ref.matrix_data);
  for (int i = 0; i < (C_ref.m_column * C_ref.m_row); i++) {
    if (res[i] != C_ref.matrix_data[i]) {
      std::cout << "ref[" << i << "]:" << (int)C_ref.matrix_data[i] << ",res[" << i << "]:" << (int)res[i] << std::endl;

      return false;
    }
  }

  return true;
}

template <typename type_t>
void test_func_model(int M, int K, int N,
                     std::function<void(int, int, int, std::vector<type_t>, std::vector<type_t>,
                                        std::vector<type_t>&)>
                         cb,
                     std::string comment, int trials = 1, bool if_check_res = false) {
  struct timeval start;
  struct timeval end;
  std::vector<int64_t> time_cost_vec;
  for (int i = 0; i < trials; ++i) {
    matrix_class<type_t> matrix_A(M, K), matrix_B(K, N), matrix_C(M, N);
    memset(&matrix_C.matrix_data[0], 0x0, matrix_C.matrix_data.size());
    gettimeofday(&start, NULL);
    cb(M, N, K, matrix_A.matrix_data, matrix_B.matrix_data, matrix_C.matrix_data);
    gettimeofday(&end, NULL);
    time_cost_vec.push_back(usec_diff(start, end));
    if (if_check_res) {
    if (0 == i) {
      if (!check_result<type_t>(matrix_C.matrix_data, M, N, K, matrix_A.matrix_data,
                                matrix_B.matrix_data)) {
        std::cout << comment << " comp error" << std::endl;
        throw;
      }
    }
    }
  }
  int64_t time_cost_sum = 0;
  for (auto time_cost : time_cost_vec) {
    time_cost_sum += time_cost;
  }
  std::cout << comment << " time cost:" << time_cost_sum / time_cost_vec.size() << std::endl;
}

#define MNK (1024)
int main(int argc, char** argv) {
  int M = MNK;
  int K = MNK;
  int N = MNK;
  int trials = 3;
  int if_check_res = true;
  // test_func_model<char>(M, K, N, normal_gemm<char>, "normal", trials);
  test_func_model<char>(M, K, N, lopp_permutation_gemm<char>, "lopp_permutation_gemm", trials);
  // test_func_model<char>(M, K, N, block_gemm<char>, "block_gemm", trials);
  test_func_model<char>(M, K, N, lopp_permutation_block_gemm<char>, "lopp_permutation_block_gemm",
                        trials);
  //test_func_model<char>(M, K, N, cache_blocking_gemm<char>, "cache_blocking_gemm", trials, if_check_res);
  // test_func_model<char>(
  //    M, K, N, cache_write_gemm<char>, "cache_write_gemm", trials);
  // test_func_model<char>(M, K, N, openmp_gemm<char>, "openmp_gemm", trials);
  test_func_model<char>(M, K, N, tile_2x2_gemm<char>, "tile_2x2_gemm", trials, if_check_res);

  return 0;
}
