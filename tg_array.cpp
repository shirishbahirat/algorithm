#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
  {
    vector<int> temp(nums.size(), 0);

    int idx = 0;
    for (int x : temp)
    {
      int sw = temp.at(index.at(idx));
      temp.at(index.at(idx)) = nums.at(idx);
      cout << temp.at(idx) << " ";

      ++idx;

      for (int k = idx; k < nums.size(); ++k)
      {
        int tx = nums[k];
        nums[k] = sw;
        sw = tx;
      }
    }
    cout << endl;
    return nums;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {0, 1, 2, 3, 4};

  vector<int> index = {0, 1, 2, 2, 1};

  vector<int> out = obj->createTargetArray(nums, index);

  return 0;
}
