#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int compute_identical(vector<int> &nums, int n)
  {

    if (nums.size() <= 1)
      return n;

    int idy = nums.at(0);
    nums.erase(nums.begin());
    int count = 0;
    int size = nums.size();

    for (int i = 0; i < nums.size(); ++i)
    {
      if (nums.at(i) == idy)
      {
        count++;
      }
    }

    int im = 0;
    while (nums.size() != (size - count))
    {
      if (nums.at(im) == idy)
      {
        nums.erase(nums.begin() + im);
      }
      else
      {
        im++;
      }
    }

    if (count > 0)
      count++;

    cout << nums.size() << " " << count << endl;

    count = ((count * (count - 1)) / 2);

    n += count;

    n = compute_identical(nums, n);

    return n;
  }

  int numIdenticalPairs(vector<int> &nums)
  {
    return compute_identical(nums, 0);
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {1, 1, 2, 2, 2};

  int count = obj->numIdenticalPairs(nums);
  cout << count << endl;
  return 0;
}
