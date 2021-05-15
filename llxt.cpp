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

  void insert_node(int data)
  {
    node *nx = new node(data);

    if (nd == nullptr)
    {
      nd = nx;
      return;
    }

    node *temp = nd;

    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    temp->next = nx;
  }

  void print_node()
  {

    node *temp = nd;

    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }

    cout << endl;
  }

  void linked_list() { return; }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->insert_node(10);
  obj->print_node();
  obj->insert_node(20);
  obj->print_node();
  obj->insert_node(30);
  obj->print_node();
  obj->insert_node(40);
  obj->print_node();
  obj->insert_node(50);
  obj->print_node();

  cout << obj->nd->data << " ";
  cout << obj->nd->next->data << " ";
  cout << obj->nd->next->next->data << " ";
  cout << obj->nd->next->next->next->data << " ";
  cout << obj->nd->next->next->next->next->data << endl;

  return 0;
}
