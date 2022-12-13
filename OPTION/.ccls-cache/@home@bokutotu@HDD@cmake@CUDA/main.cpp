#include "Config.h"
#include <iostream>

using namespace std;

int main(void) {
#ifdef GPU
  std::cout << "GPU" << std::endl;
#else
  std::cout << "CPU" << std::endl;
#endif // GPU
}
