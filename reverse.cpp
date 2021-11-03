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

void reverse(node *n)
{

  if (n == nullptr)
    return;

  node *t;

  in_order(n->left);
  in_order(n->right);

  t = n->left;
  n->left = n->right;
  n->right = t;
}

void in_order(node *n)
{

  if (n == nullptr)
    return;

  in_order(n->left);
  cout << n->data << " ";
  in_order(n->right);
}

void pre_order(node *n)
{

  if (n == nullptr)
    return;

  cout << n->data << " ";
  in_order(n->left);
  in_order(n->right);
}

void post_order(node *n)
{

  if (n == nullptr)
    return;

  in_order(n->left);
  in_order(n->right);
  cout << n->data << " ";
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

  pre_order(root);
  cout << endl;

  post_order(root);
  cout << endl;

  return 0;
}
