#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  struct node
  {
    int data;
    node *next;

    node(int d) : data(d), next(nullptr) {}
  };

  void linked_list() { return; }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
