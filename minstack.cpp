#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
public:
  /** initialize your data structure here. */
  MinStack() : min(0x7FFFFFF) {}

  void push(int x) {}

  void pop() {}

  int top() { return 0; }

  int getMin() { return min; }

private:
  vector<int> stack;
  int min;
};

int main(int argc, char const *argv[])
{
  MinStack *obj = new MinStack();
  return 0;
}
