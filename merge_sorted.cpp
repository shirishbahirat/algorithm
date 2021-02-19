#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {

    if (!n)
      return;

    vector<int> temp;

    int x = 0, y = 0;

    while (m && n)
    {
      if (nums1.at(x) < nums2.at(y))
      {
        temp.push_back(nums1.at(x));
        ++x;
        --m;
      }
      else
      {
        temp.push_back(nums2.at(y));
        ++y;
        --n;
      }
    }

    while (m)
    {
      temp.push_back(nums1.at(x));
      ++x;
      --m;
    }

    while (n)
    {
      temp.push_back(nums2.at(y));
      ++y;
      --n;
    }

    nums1 = temp;
  }
};

int main(int argc, char const *argv[])
{

  vector<int> nums1 = {4, 0, 0, 0, 0, 0};
  int m = 1;
  vector<int> nums2 = {1, 2, 3, 5, 6};
  int n = 5;

  Solution *soln = new Solution();

  soln->merge(nums1, m, nums2, n);

  for (int i = 0; i < m; ++i)
  {
    cout << nums1.at(i) << " ";
  }
  cout << endl;

  for (int i = 0; i < n; ++i)
  {
    cout << nums2.at(i) << " ";
  }
  cout << endl;

  for (int i = 0; i < nums1.size(); ++i)
  {
    cout << nums1.at(i) << " ";
  }
  cout << endl;

  return 0;
}