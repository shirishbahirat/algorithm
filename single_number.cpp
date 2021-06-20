#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {

    map<int, int> count;

    for (int i = 0; i < nums.size(); ++i)
    {
      int idx = nums[i];
      count[idx]++;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
      int idx = nums[i];
      if (count[idx] == 1)
        return idx;
    }

    return 0;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {4, 1, 2, 1, 2};

  cout << obj->singleNumber(nums) << endl;

  return 0;
}
