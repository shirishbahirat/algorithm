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
  n->left = nullptr;

  return n;
}

int main(int argc, const char *argv[])
{

  node *root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(3);
  root->left->left = new_node(4);
  root->left->right = new_node(5);
  root->right->left = new_node(6);
  root->right->right = new_node(7);

  return 0;
}