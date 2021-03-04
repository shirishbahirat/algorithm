#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
  {

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
