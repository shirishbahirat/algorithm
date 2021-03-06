#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int xorOperation(int n, int start)
  {

    // vector<int> nums(n, 0);
    int xo = 0;

    for (int i = 0; i < n; ++i)
    {
      // nums[i] = start + (2 * i);
      // xo ^= nums[i];
      xo ^= start + (2 * i);
    }

    return xo;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->xorOperation(5, 0) << endl;

  return 0;
}
