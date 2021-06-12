#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;

  node(int d) : data(d), left(nullptr), right(nullptr) {}
};

int main(int argc, const char *argv[])
{

  node *n = new node(10);
  node *a = new node(9);
  node *b = new node(11);

  n->left = a;
  n->right = b;

  return 0;
}