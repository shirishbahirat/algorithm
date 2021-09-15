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

void insert_node(node **new_node, int data, int tag)
{

  node *n = *new_node;

  if (n == nullptr)
  {
    *new_node = new node(data, tag);
  }

  // cout << (*)new_node->data << endl;

  return;
}

int main(int argc, char const *argv[])
{

  node *pifo = nullptr;

  insert_node(&pifo, 10, 11);

  cout << pifo->data << endl;

  return 0;
}
