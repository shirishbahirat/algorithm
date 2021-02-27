#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int max = -2147483648;
    for (int i = 0; i < nums.size(); ++i)
    {
      int moving_sum = 0;
      for (int j = i; j < nums.size(); ++j)
      {
        moving_sum += nums[j];
        if (moving_sum > max)
          max = moving_sum;
      }
    }

    return max;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int sum = obj->maxSubArray(nums);

  return 0;
}
