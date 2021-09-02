#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int climbStairs(int n) { return 1; }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->climbStairs(3) << endl;

  return 0;
}
