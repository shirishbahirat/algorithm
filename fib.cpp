#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int fib(int num)
  {

    if ((num == 1) || (num == 2))
      return 1;

    return fib(num - 1) + fib(num - 2);
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  cout << obj->fib(10) << endl;
  return 0;
}
