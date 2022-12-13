#include <iostream>
#include "Config.h"

#ifdef !GPU
#include "../hello.hpp"

using namespace std;

void hello() {
  std::cout << "hello from cpu" << std::endl;
}
#endif // cpu
