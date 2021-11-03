#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

node *new_node(int data)
{
  node *n = new node();
  n->data = data;
  n->left = nullptr;
  n->right = nullptr;

  return n;
}

void in_order(node *n)
{
  if (n == nullptr)
    return;

  in_order(n->left);
  cout << n->data << " ";
  in_order(n->right);
}

int main(int argc, const char *argv[]) { return 0; }
