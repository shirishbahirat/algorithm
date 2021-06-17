#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool validMountainArray(vector<int> &arr)
  {
    int i = 0;

    while ((arr[i] < arr[i - 1]) && (i < arr.size()))
    {
      i++;
    }

    if ((i == 1) || (i == arr.size()))
      return false;

    while ((arr[i] > arr[i - 1]) && (i < arr.size()))
    {
      i++;
    }

    if (i == arr.size())
      return true;

    return false;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
