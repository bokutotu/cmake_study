#include <iostream>

#include "kernel.h"
#include "cuda_runtime.h"

void alloc_gpu(float *dst, int size) {
  CHECK(cudaMalloc((float**)&dst, sizeof(float) * size));
}

void cpy_cuda(float *dst, float *src, int size, cudaMemcpyKind kind) {
  CHECK(cudaMemcpy(dst, src, sizeof(float) * size, kind));
}

void cpy_cpu2gpu(float *src, float *dst, int size) {
  CHECK(cudaMemcpy(dst, src, sizeof(float) * size, cudaMemcpyHostToDevice));
}

void cpy_gpu2cpu(float *src, float *dst, int size) {
  CHECK(cudaMemcpy((void**)&dst, (void**)&src, sizeof(float) * size, cudaMemcpyDeviceToHost));
}

__global__ void sum_gpu(float *a, float *b, float *c, int size) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx >= size) {
    return ;
  }
  c[idx] = a[idx] + b[idx];
}

void sum(float *a, float *b, float *c, int size) {
  dim3 block(32);
  dim3 grid((size + block.x - 1) / block.x);
  sum_gpu <<< grid, block >>> (a, b, c, size);
  CHECK(cudaDeviceSynchronize());
}
