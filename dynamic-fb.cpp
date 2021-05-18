#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> v;

  Solution() : v(60, -1) {}

  ~Solution() {}

  int fib(int number)
  {
    if (number == 0)
      return 0;

    if (number <= 2)
      return 1;

    if (v[number] < 0)
      v[number] = fib(number - 1) + fib(number - 2);

    return v[number];
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->fib(0) << endl;
  cout << obj->fib(1) << endl;
  cout << obj->fib(2) << endl;
  cout << obj->fib(3) << endl;
  cout << obj->fib(4) << endl;
  cout << obj->fib(5) << endl;
  cout << obj->fib(6) << endl;
  cout << obj->fib(7) << endl;
  cout << obj->fib(8) << endl;
  cout << obj->fib(9) << endl;

  cout << obj->fib(25) << endl;
  cout << obj->fib(35) << endl;

  return 0;
}
