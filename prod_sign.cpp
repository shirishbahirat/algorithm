#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int pivotIndex(vector<int> &nums) { return 0; }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {-1, -2, -3, -4, 3, 2, 1};

  cout << obj->pivotIndex(nums) << endl;

  return 0;
}
