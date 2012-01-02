#include "../src/Timer.hpp"
#include <iostream>

void f() {
  TIMER_FUNC();
  sleep(1);
}

void g() {
  TIMER_FUNC();
  sleep(1);
}

int main(void)
{
  {
    TIMER_FUNC();
    f();
    g();
    g();
    g();
  }
  std::cout << Timer::GetReport();
  return 0;
}
