#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int average(vector<int> &nums)
  {
    int avg = 0;

    for (int x : nums)
    {
      avg += x;
    }

    avg /= nums.size();

    return avg;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {10, 11, 2, 56, 3, 9, 34};
  cout << obj->average(nums) << endl;
  return 0;
}
