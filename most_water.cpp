#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {

    int idx = 0;
    int idy = height.size();
    int max_area = 0;
    bool flag = false;

    while (idx < idy)
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
      if (flag == false)
      {
        idx++;
        flag = true;
      }
      else
      {
        idy--;
        flag = false;
      }
    }

    return max_area;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  cout << "Max area " << obj->maxArea(height) << endl;

  return 0;
}
