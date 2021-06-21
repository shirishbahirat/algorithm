#include <iostream>
#include <vector>

using namespace std;

class Solution class Solution
{
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4)
  {

    int cnt = 0;
    unordered_map<int, int> m;
    for (int a : nums1)
      for (int b : nums2)
        ++m[a + b];
    for (int c : nums3)
      for (int d : nums4)
      {
        auto it = m.find(-(c + d));
        if (it != end(m))
          cnt += it->second;
      }
    return cnt;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  return 0;
}
