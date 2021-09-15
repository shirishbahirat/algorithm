#include <iostream>
#include <vector>

using namespace std;

struct node
{
  int data;
  int tag;
  node *next;

  node(int d, int t) : data(d), tag(t), next(nullptr) {}
};

void insert_node(node **new_node)
{

  node *n = *new_node;

  if (n == nullptr)
  {
    n = new node(10, 11);
  }
}

int main(int argc, char const *argv[])
{

  node *pifo = nullptr;

  insert_node(&pifo);

  // cout << pifo->data << endl;

  return 0;
}
