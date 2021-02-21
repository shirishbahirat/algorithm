#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> shuffle(vector<int> &nums, int n)
  {

    vector<int> temp(nums.size(), 0);

    for (int i = 0, j = 0, k = n, l = 1; i < n && k < nums.size();
         ++i, j += 2, ++k, l += 2)
    {
      temp.at(j) = nums.at(i);
      temp.at(l) = nums.at(k);
    }

    return temp;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {2, 5, 1, 3, 4, 7};
  int n = 3;

  nums = obj->shuffle(nums, n);

  for (int i = 0; i < nums.size(); ++i)
  {
    cout << nums.at(i) << " ";
  }

  cout << endl;

  return 0;
}
