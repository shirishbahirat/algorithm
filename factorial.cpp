#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int factorial(int num)
  {
    if (num == 1)
      return 1;

    return num * factorial(num - 1);
  }
};
int main(int argc, char const *argv[])
{

  Solution *obj = new Solution();

  cout << obj->factorial(10) << endl;

  return 0;
}
