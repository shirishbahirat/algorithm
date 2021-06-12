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

void print(node *head)
{
  if (head == nullptr)
    return;

  print(head->left);

  cout << head->data << " ";

  print(head->right);
}

void invert(struct node *head)
{
  if (head == nullptr)
    return;
  else
  {
    struct node *temp;

    invert(head->left);
    invert(head->right);

    temp = head->left;
    head->left = head->right;
    head->right = temp;
  }
}

int main(int argc, const char *argv[])
{

  node *n = new node(10);
  node *a = new node(9);
  node *b = new node(11);

  n->left = a;
  n->right = b;

  node *x = new node(8);
  node *y = new node(7);

  n->left->left = x;
  n->left->right = y;

  node *m = new node(5);
  node *o = new node(6);

  n->right->left = o;
  n->right->right = m;

  cout << isbalanced(n) << endl;

  print(n);

  cout << endl;

  invert(n);
  print(n);

  cout << endl;

  return 0;
}