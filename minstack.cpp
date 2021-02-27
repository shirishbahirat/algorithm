#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
public:
  /** initialize your data structure here. */
  MinStack() : min(0x7FFFFFFFFFFFFFF) {}

  void push(long int x)
  {
    stack.insert(stack.begin(), x);
    if (x < min)
      min = x;
  }

  void pop()
  {

    bool get_min;

    if (min == stack[0])
    {
      get_min = true;
    }

    stack.erase(stack.begin());

    if (get_min)
    {
      min = 0x7FFFFFFFFFFFFFF;
      for (int i = 0; i < stack.size(); ++i)
      {
        if (stack[i] < min)
          min = stack[i];
      }
    }
  }

  int top() { return stack[0]; }

  int getMin() { return min; }

private:
  vector<long int> stack;
  long int min;
};

int main(int argc, char const *argv[])
{
  MinStack *obj = new MinStack();

  obj->push(-2);
  obj->push(0);
  obj->push(-3);

  cout << obj->getMin() << endl;

  obj->pop();

  cout << "yop " << obj->top() << endl;
  cout << obj->getMin() << endl;

  return 0;
}
