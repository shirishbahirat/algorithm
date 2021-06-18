#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {

    int idx = 0;
    int idy = height.size() - 1;
    int max_area = 0;

    while (idx <= idy)
    {
      int width = (idy - idx);
      int length = 0;
      if (height[idx] < height[idy])
      {
        length = height[idx];
      }
      else
      {
        length = height[idy];
      }

      int area = length * width;

      if (area > max_area)
      {
        max_area = area;
      }

      if (height[idx] < height[idy])
      {
        idx++;
      }
      else
      {
        idy--;
      }
    }

    return max_area;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> height = {2, 3, 10, 5, 7, 8, 9};

  cout << "Max area " << obj->maxArea(height) << endl;

  return 0;
}
