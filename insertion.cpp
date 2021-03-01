#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void sort(vector<int> &nums) { return; }
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
