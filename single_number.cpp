#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums) { return 0; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {4, 1, 2, 1, 2};

  cout << obj->singleNumber(nums) << endl;

  return 0;
}
