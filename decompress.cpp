#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> decompressRLElist(vector<int> &nums)
  {

    vector<int> decompressed;

    for (int i = 0, j = 1; j < nums.size(); i += 2, j += 2)
    {
      cout << nums.at(i) << " " << nums.at(j) << endl;

      for (int x = 0; x < nums.at(i); ++x)
      {
        decompressed.push_back(nums.at(j));
      }
    }

    return decompressed;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {1, 2, 3, 4};

  vector<int> decompressed = obj->decompressRLElist(nums);

  for (int i = 0; i < decompressed.size(); ++i)
  {
    cout << decompressed.at(i) << " ";
  }
  cout << endl;

  return 0;
}
