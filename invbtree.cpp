#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;

  node(int d) : data(d), left(nullptr), right(nullptr) {}
};

bool isbalanced(node *head)
{
  if ((head->left == nullptr) && (head->right == nullptr))
    return true;

  if ((head->left == nullptr) || (head->right == nullptr))
    return false;

  return isbalanced(head->left) && isbalanced(head->right);
}

int main(int argc, const char *argv[])
{

  node *n = new node(10);
  node *a = new node(9);
  node *b = new node(11);

  n->left = a;
  n->right = b;

  node *x = new node(9);
  node *y = new node(9);

  n->left->left = x;
  n->left->right = y;

  cout << isbalanced(n) << endl;

  return 0;
}