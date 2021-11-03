#include <iostream>

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

int main(int argc, const char *argv[]) { return 0; }
