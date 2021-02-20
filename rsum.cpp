#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> runningSum(vector<int> &nums)
  {

    int sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
      sum += nums[i];
      nums[i] = sum;
    }

    return nums;
  }
};

int main(int argc, char const *argv[])
{

  vector<int> nums = {1, 2, 3, 4};

  Solution *soln = new Solution();

  nums = soln->runningSum(nums);

  for (int i = 0; i < nums.size(); ++i)
  {
    cout << nums[i] << " ";
  }

  cout << endl;

  return 0;
}