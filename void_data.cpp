#include <iostream>
using namespace std;

int a[6] = {[4] = 29, [2] = 15};

struct node
{
  int data;
  node *next;

  node(int d) : data(d), next(NULL) {}
};

int add_node(void *data)
{

  node *n = (node *)data;

  cout << n->data << endl;

  return 0;
}

int main(int argc, char const *argv[])
{

  node *n1 = new node(1000);

  add_node((void *)n1);

  for (int i = 0; i < 6; ++i)
  {
    cout << a[i] << " ";
  }

  cout << endl;

  return 0;
}