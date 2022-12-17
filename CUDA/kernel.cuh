void alloc_gpu(float *dst, int size);
void cpy_cpu2gpu(float *src, float *dst, int size);
void cpy_gpu2cpu(float *src, float *dst, int size);
__device__ void sum(float *a, float *b, float *c, int size);
