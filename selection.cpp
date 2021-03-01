#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void sort(vector<int> &nums)
  {

    for (int i = 0; i < nums.size(); ++i)
    {
      int smallest = INT_MAX;
      int idx = 0;
      for (int j = i; j < nums.size(); ++j)
      {
        if (nums[j] < smallest)
        {
          smallest = nums[j];
          idx = j;
        }
      }

      if (idx > i)
      {
        int temp = nums[i];
        nums[i] = nums[idx];
        nums[idx] = temp;
      }
    }

    return;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {4, 5, 3, 2, 7, 1, 9, 0};

  obj->sort(nums);

  for (auto x : nums)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
