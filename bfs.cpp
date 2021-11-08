#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

int main(int argc, const char *argv[])
{

  node *btree = new node();
  btree->data = 10;

  return 0;
}