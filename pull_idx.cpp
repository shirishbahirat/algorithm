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

  if (*new_node == nullptr)
  {
    *new_node = new node(data, tag);
  }
  else
  {
    while (*new_node->next != nullptr)
    {
      *new_node = *new_node->next;
    }
  }

  return;
}

int main(int argc, char const *argv[])
{

  node *pifo = nullptr;

  insert_node(&pifo, 10, 11);

  cout << pifo->data << endl;

  return 0;
}
