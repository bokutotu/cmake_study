#include <iostream>
#include <unistd.h>
#include "cuda_runtime.h"

#include "kernel.h"

using namespace std;

// int main(int argc, char **arg) {
//   cudaSetDevice(0);
//   int size = 1024;
//
//   float *a = (float*)malloc(sizeof(float) * size);
//   float *b = (float*)malloc(sizeof(float) * size);
//   float *c = (float*)malloc(sizeof(float) * size);
//
//   for (int i = 0; i < size; i ++) {
//     a[i] = static_cast<float>(i);
//     b[i] = static_cast<float>(i) * 2.;
//     c[i] = 0;
//   }
//
//   float *dA, *dB, *dC;
//   alloc_gpu(dA, size);
//   alloc_gpu(dB, size);
//   alloc_gpu(dC, size);
//
//   cpy_cpu2gpu(a, dA, size);
//   cpy_cpu2gpu(b, dB, size);
//   cpy_cpu2gpu(c, dC, size);
//
//   sum(dA, dB, dC, size);
//
//   cpy_gpu2cpu(dC, c, size);
//
//   for (int i = 0; i < size; i++) {
//     std::cout << c[i] << " " ;
//   }
//   
// }

int main(int argc, char **arg) {
  cudaSetDevice(0);
  int size = 1024;

  float *a = (float *)malloc(sizeof(float) * size);
  float *b = (float *)malloc(sizeof(float) * size);
  float *c = (float *)malloc(sizeof(float) * size);

  for (int i = 0; i < size; i++) {
    a[i] = i;
    b[i] = i * 2;
  }

  float *d_A, *d_B, *d_C;

  CHECK(cudaMalloc((float **)&d_A, sizeof(float) * size));
  CHECK(cudaMalloc((float **)&d_B, sizeof(float) * size));
  CHECK(cudaMalloc((float **)&d_C, sizeof(float) * size));

  cpy_cuda(d_A, a, size, cudaMemcpyHostToDevice);
  cpy_cuda(d_B, b, size, cudaMemcpyHostToDevice);

  sum(d_A, d_B, d_C, size);

  cpy_cuda(c, d_C, size, cudaMemcpyDeviceToHost);
  for (int i = 0; i < size; i++ ) {
    std::cout << c[i] << " ";
  }
}
