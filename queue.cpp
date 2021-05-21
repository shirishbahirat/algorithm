#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : queue(nullptr) {}
  ~Solution() {}

  struct node
  {
    int data;
    node *next;

    node(int d) : data(d), next(nullptr) {}
  };

  node *queue;

  void push(int data)
  {

    node *item = new node(data);

    if (queue == nullptr)
    {
      queue = item;
      return;
    }

    node *temp = queue;

    while (temp->next)
    {
      temp = temp->next;
    }

    temp->next = item;

    return;
  }

  void print(void)
  {
    node *temp = queue;

    while (temp)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }

    cout << endl;

    return;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->push(10);
  obj->push(20);
  obj->push(30);
  obj->push(40);
  obj->push(50);
  obj->push(60);

  obj->print();

  return 0;
}
