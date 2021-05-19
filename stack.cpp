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

    node *head = new_node;

    head->next = stack;
    stack = head;

    return;
  }

  void print()
  {
    node *temp = stack;

    while (temp)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;

    return;
  }

  int pop()
  {
    if (stack)
    {
      int data = stack->data;

      node *new_head = stack->next;

      delete stack;

      stack = new_head;

      return data;
    }
    else
    {
      return -1;
    }
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->push(1);
  obj->push(2);
  obj->push(3);
  obj->push(4);
  obj->push(5);
  obj->push(6);

  obj->print();

  cout << "pop " << obj->pop() << endl;

  obj->print();

  cout << "pop " << obj->pop() << endl;

  obj->print();

  cout << "pop " << obj->pop() << endl;

  obj->print();

  return 0;
}
