#include "../include/lib2.h"

#include "shared.h"

#include <iostream>

void export_function() {
  std::cout << "this is lib 2 export_function" << std::endl;
  print_version();
  std::cout << "this is after call LIB" << std::endl;
}
