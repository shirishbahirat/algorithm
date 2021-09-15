#include <iostream>
#include <vector>

using namespace std;

struct node
{
  int data;
  int tag;
  int valid;
  node *next;

  node(int d, int t, int v) : data(d), tag(t), valid(v), next(nullptr) {}
};

node *insert_node(node *head, int data, int tag)
{

  if (head == nullptr)
  {
    head = new node(data, tag, 1);
  }
  else
  {
    node *temp = head;
    while (head->next != nullptr)
    {
      head = head->next;
    }
    head->next = new node(data, tag, 1);
    head = temp;
  }

  return head;
}

node *get_node(node *head, int tag)
{

  node *temp = head;

  while (temp->tag != tag)
  {
    temp = temp->next;
  }

  temp->valid = 0;

  return temp;
}

node *remove_node(node *head)
{
  node *temp = head;

  while (temp->valid != 0)
  {
    temp = temp->next;
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

  cout << n->tag << endl;

  return 0;
}
