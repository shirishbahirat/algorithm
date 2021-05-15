#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  Solution() : b(nullptr) {}
  ~Solution() {}

  void add_node(int data)
  {
    insert(&b, data);
    return;
  }

  struct node
  {
    int data;
    node *left;
    node *right;

    node(int d) : data(d), left(nullptr), right(nullptr) {}
  };

  node *b;

  void insert(node **n, int data)
  {

    if (*n == nullptr)
    {
      node *x = new node(data);
      *n = x;
      return;
    }

    node *x = *n;
    if (data <= x->data)
    {
      insert(&(*n)->left, data);
    }
    else
    {
      insert(&(*n)->right, data);
    }

    return;
  }

  void transverse(node **n)
  {
    if (*n == nullptr)
    {
      return;
    }
    cout << *&(*n)->data << endl;

    transverse(&(*n)->left);
    transverse(&(*n)->right);
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  obj->add_node(10);
  obj->add_node(8);
  obj->add_node(20);
  obj->add_node(30);
  obj->add_node(25);
  cout << obj->b->data << endl;
  cout << obj->b->left->data << endl;
  cout << obj->b->right->data << endl;
  cout << obj->b->right->right->data << endl;
  cout << obj->b->right->right->left->data << endl;
  cout << endl;
  obj->transverse(&(obj->b));

  return 0;
}
