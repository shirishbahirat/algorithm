#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : nd(nullptr) {}
  ~Solution() {}

  struct node
  {
    int data;
    node *next;

    node(int d) : data(d), next(nullptr) {}
  };

  node *nd;

  void insert(int data)
  {

    node *new_node = new node(data);

    if (nd == nullptr)
    {
      nd = new_node;
      return;
    }

    node *temp = nd;

    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    temp->next = new_node;

    return;
  }

  void print(void)
  {

    node *temp = nd;

    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }

    cout << endl;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->insert(10);
  obj->insert(20);
  obj->insert(30);
  obj->insert(40);
  obj->insert(50);

  obj->print();

  return 0;
}
