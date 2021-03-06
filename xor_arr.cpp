#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int xorOperation(int n, int start)
  {

    vector<int> nums(n, 0);

    for (int i = 0; i < n; ++i)
    {
      nums[i] = start + (2 * i);
    }

    return 10;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->xorOperation(5, 1);

  return 0;
}
