#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

int test_function(int a, ...) { return 0; }

node *new_node(int data)
{

  node *n = new node();
  n->data = data;
  n->left = nullptr;
  n->left = nullptr;

  return n;
}

void post_order(node *n)
{

  if (n == nullptr)
    return;

  post_order(n->left);
  post_order(n->right);
  cout << n->data << " ";
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
  pre_order(n->left);
  pre_order(n->right);
}

int main(int argc, const char *argv[])
{

  if (argc > 1)
  {

    if (strcmp(argv[1], "-h") == 0)
    {
      cout << "Received " << argv[2] << endl;
    }

    if (strcmp(argv[3], "-k") == 0)
    {
      cout << "Received " << argv[4] << endl;
    }
  }

  node *root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(3);
  root->left->left = new_node(4);
  root->left->right = new_node(5);
  root->right->left = new_node(6);
  root->right->right = new_node(7);

  in_order(root);
  cout << endl;

  pre_order(root);
  cout << endl;

  post_order(root);
  cout << endl;

  return 0;
}