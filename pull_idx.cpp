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

node *get_node(node *head, int tag)
{

  node *temp = head;

  while (temp->data != tag)
  {
    temp = temp->next;
    cout << temp->data >> endl;
  }

  return temp;
}

int main(int argc, char const *argv[])
{

  node *pifo = nullptr;

  pifo = insert_node(pifo, 10, 11);
  pifo = insert_node(pifo, 11, 12);
  pifo = insert_node(pifo, 13, 14);

  cout << pifo->next->next->data << endl;

  node *n = get_node(pifo, 14);

  return 0;
}
