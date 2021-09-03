#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {

    if (n < 3)
      return n;

    int current = 0;
    int prev = 2;
    int prev_prev = 1;

    for (int i = 3; i <= n; i++)
    {
      current = prev_prev + prev;
      prev_prev = prev;
      prev = current;
    }

    return current;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->climbStairs(3) << endl;

  return 0;
}
