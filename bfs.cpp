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

  node *btree = new node();
  btree->data = 10;

  return 0;
}