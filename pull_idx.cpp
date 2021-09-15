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

node *insert_node(node *head, int data, int tag)
{

  if (head == nullptr)
  {
    head = new node(data, tag);
  }

  return head;
}

int main(int argc, char const *argv[])
{

  node *pifo = nullptr;

  pifo = insert_node(pifo, 10, 11);
  // insert_node(pifo, 11, 12);

  cout << pifo->data << endl;

  return 0;
}
