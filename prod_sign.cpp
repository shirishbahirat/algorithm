#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {

    int result = 1;

    for (int i = 0; i < nums.size(); ++i)
    {
      if (nums.at(i) > 0)
        nums.at(i) = 1;
      else if (nums.at(i) < 0)
        nums.at(i) = -1;
      else if (nums.at(i) == 0)
        return 0;

      result *= nums.at(i);
    }

    return result;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {-1, -2, -3, -4, 3, 2, -1};

  cout << obj->pivotIndex(nums) << endl;

  return 0;
}
