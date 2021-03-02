#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void sort(vector<int> &nums)
  {

    if (nums.size() < 1)
      return;

    int left = 0, right = nums.size(), mid = (0 + nums.size()) / 2;

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
