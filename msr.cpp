#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : arr{6, 5, 4, 1, 2, 8, 3, 9} {}

  void merge(int arr[], int lo, int hi)
  {

    if (hi > lo)
    {
      int mid = lo + (hi - lo) / 2;
      merge(arr, lo, mid);
      merge(arr, mid + 1, hi);
    }
  }

  void sort(void)
  {

    merge(arr, 0, 7);

    return;
  }

  int arr[];
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->sort();

  return 0;
}
