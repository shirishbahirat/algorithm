#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : stack(nullptr) {}
  ~Solution() {}

  struct node
  {
    int data;
    node *next;

    node(int d) : data(d), next(nullptr) {}
  };

  node *stack;

  void push(int data)
  {

    node *new_node = new node(data);

    if (stack == nullptr)
    {
      stack = new_node;
      return;
    }

    return;
  }

  int pop() { return 0; }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
