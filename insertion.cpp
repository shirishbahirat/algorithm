#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void sort(vector<int> &nums)
  {
    for (int i = 1; i < nums.size(); i++)
    {
      int value = nums[i];
      int hole = i;
      while (hole > 0 && nums[hole - 1] > value)
      {
        nums[hole] = nums[hole - 1];
        hole--;
        cout << " hole while loop " << hole << " value " << value << endl;
      }
      nums[hole] = value;

      for (auto x : nums)
      {
        cout << x << " ";
      }
      cout << " hole " << value << endl;
    }
    return;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {4, 5, 2, 3, 7, 0, 9, 1};

  obj->sort(nums);

  for (auto x : nums)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
