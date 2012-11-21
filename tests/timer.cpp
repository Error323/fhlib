#include "../src/Timer.hpp"
#include <iostream>

void f() {
  PROFILE_FUNCTION();
  sleep(1);
}

void g() {
  PROFILE_FUNCTION();
  sleep(1);
}

int main(void)
{
  {
    PROFILE_FUNCTION();
    f();
    g();
    g();
    g();
  }
  std::cout << Timer::GetReport();
  return 0;
}
