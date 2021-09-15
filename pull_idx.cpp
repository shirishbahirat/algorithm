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
  else
  {
    node *temp = head;
    while (head->next != nullptr)
    {
      head = head->next;
    }
    head->next = new node(data, tag);
    head = temp;
  }

  return head;
}

int main(int argc, char const *argv[])
{

  node *pifo = nullptr;

  pifo = insert_node(pifo, 10, 11);
  pifo = insert_node(pifo, 11, 12);

  cout << pifo->next->data << endl;

  return 0;
}
