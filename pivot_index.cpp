#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {

    int idl = 0;
    int idr = nums.size() - 1;

    int lsum = 0;
    int rsum = 0;

    while (idr > idl)
    {
      if (lsum > (rsum + nums[idr]))
      {
        rsum += nums[idr--];
      }
      else // if (lsum < (rsum + nums[idr]))
      {
        lsum += nums[idl++];
      }
    }

    cout << lsum << " " << rsum << endl;
    return 0;
  }
};

int main(int argc, char const *argv[])
{

  vector<int> nums = {1, 7, 3, 6, 5, 6};
  Solution *obj = new Solution();

  int out = obj->pivotIndex(nums);
  return 0;
}
