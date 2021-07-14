#include <iostream>

using namespace std;

void largest(int a)
{

  cout << a << endl;

  return;
}

int main(int argc, char const *argv[])
{

  int w = 11;
  auto m = [](int x) { return x + 20; };
  auto p = [w]() { return (w + 20); };

  void (*f)(int) = [](int i) { std::cout << i; };

  largest(m(201));
  largest(p());

  cout << m(10) << endl;

  return 0;
}