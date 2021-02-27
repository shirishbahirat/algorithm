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
      if ((nums[idr] > 0) || (nums[idl] > 0))
      {
        if (lsum < (rsum + nums[idr]))
        {
          lsum += nums[idl++];
        }
        else if (rsum < (lsum + nums[idl]))
        {
          rsum += nums[idr--];
        }
      }
      else
      {
        if (lsum > (rsum + nums[idr]))
        {
          lsum += nums[idl++];
        }
        else if (rsum > (lsum + nums[idl]))
        {
          rsum += nums[idr--];
        }
      }
    }

    if (rsum == lsum)
      return idr;
    else
      return -1;
  }
};

int main(int argc, char const *argv[])
{

  vector<int> nums = {-1, -1, -1, -1, -1, -1};
  Solution *obj = new Solution();

  int out = obj->pivotIndex(nums);

  cout << out << endl;
  return 0;
}
