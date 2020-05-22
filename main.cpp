#include <iostream>
#include "src/utils/NetworkUtils.h"

int main() {
  const std::string ipAddress = NetworkUtils::ip();
  std::cout << ipAddress << std::endl;

  return 0;
}
