#include <iostream>
using namespace std;

int main()
{
  [](int x, int y) { cout << "sum is " << x + y << endl; }(10, 30);

  int value = 25;
  auto func = [=](int a, int b) {
    cout << "another sum is " << a + b + value << endl;
    return a + b + value;
  };

  func(6, 3);
}