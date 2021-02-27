#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> frequencySort(vector<int> &nums)
  {
    map<int, int> frequency;
    map<int, vector<int>> ordered;

    for (int i = 0; i < nums.size(); ++i)
    {
      frequency[nums[i]] += 1;
    }

    return nums;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {4, 4, 1};

  nums = obj->frequencySort(nums);

  for (int i = 0; i < nums.size(); ++i)
  {
    cout << nums[i] << " ";
  }

  cout << endl;
  return 0;
}
