#include <iostream>

struct node
{
  int data;
  node *next;

  node(int d) : data(d), next(NULL) {}
};

int add_node(void *data) { return 0; }

int main(int argc, char const *argv[])
{

  node *n1 = new node(10);

  add_node((void *)n1);

  return 0;
}