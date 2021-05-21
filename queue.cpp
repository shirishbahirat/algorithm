#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() {}
  ~Solution() {}

  struct node
  {
    int data;
    node *next;

    node(int d) : data(d), next(nullptr) {}
  };

  int pivotIndex(vector<int> &nums) { return 0; }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
