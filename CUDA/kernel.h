#pragma once

#include "cuda_runtime.h"

#define CHECK(call)                                                            \
{                                                                              \
  const cudaError_t error = call;                                              \
  if (error != cudaSuccess)                                                    \
  {                                                                            \
     printf("Error: %s:%d,  ", __FILE__, __LINE__);                            \
     printf("code:%d reason: %s\n", error, cudaGetErrorString(error));         \
     exit(1);                                                                  \
  }                                                                            \
}                                                                              \

void alloc_gpu(float *dst, int size);
void cpy_cuda(float *src, float *dst, int size, cudaMemcpyKind kind);
void cpy_cpu2gpu(float *src, float *dst, int size);
void cpy_gpu2cpu(float *src, float *dst, int size);
void sum(float *a, float *b, float *c, int size);
