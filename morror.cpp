#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

int fib(int n)
{
  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  return fib(n - 1) + fib(n - 2);
}

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

  cout << "in order " << n->data << endl;

  in_order(n->left);
  cout << "p " << n->data << endl;
  in_order(n->right);
}

void mirror_order(node *n)
{
  if (n == nullptr)
    return;

  node *temp;

  mirror_order(n->left);
  mirror_order(n->right);

  temp = n->left;
  n->left = n->right;
  n->right = temp;
}

int main(int argc, const char *argv[])
{

  node *root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(3);
  root->left->left = new_node(4);
  root->left->right = new_node(5);

  in_order(root);
  cout << endl;

  mirror_order(root);

  in_order(root);
  cout << endl;

  return 0;
}
