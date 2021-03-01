#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void sort(vector<int> &nums)
  {

    bool swaped = true;
    while (swaped)
    {
      swaped = false;
      for (int i = 1; i < nums.size(); ++i)
      {
        if (nums[i - 1] > nums[i])
        {
          int temp = nums[i - 1];
          nums[i - 1] = nums[i];
          nums[i] = temp;
          swaped = true;
        }
      }
    }

    return;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {5, 2, 3, 1, 0, 9, 6};

  obj->sort(nums);

  for (int i = 0; i < nums.size(); ++i)
  {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
