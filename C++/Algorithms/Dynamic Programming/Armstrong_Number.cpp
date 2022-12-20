#include <cmath>
#include <iostream>

namespace Dynamic_Programming {
class Armstrong_Number {
public:
  bool find(int_fast64_t num) {
    int temp{0}, rem{0}, count{0}, sum{0};
    temp = num;
    while (temp != 0) {
      temp /= 10;
      count++;
    }
    temp = num;
    while (temp != 0) {
      rem = temp % 10;
      sum += static_cast<int>(std::pow(rem, count));
      temp /= 10;
    }
    if (sum == num) {
      return true;
    } else {
      return false;
    }
    return false;
  }
};
}; // namespace Dynamic_Programming

int main() {
  Dynamic_Programming::Armstrong_Number an;
  std::cout << std::boolalpha << an.find(371) << std::endl;
  std::cout << std::boolalpha << an.find(153) << std::endl;
  std::cout << std::boolalpha << an.find(377) << std::endl;
  return 0;
}
