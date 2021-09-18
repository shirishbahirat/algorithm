#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
  node *prev;
  int tag;

  node(int d, int t) : data(d), tag(t), next(nullptr), prev(nullptr) {}
};

void insert_node(node **new_node, int tag, int data)
{

  node *n = new node(data, tag);
  node *temp = *new_node;

  if (*new_node == nullptr)
  {
    *new_node = n;
  }
  else
  {
    while ((*new_node)->next != nullptr)
    {
      *new_node = (*new_node)->next;
    }
    (*new_node)->next = n;
    *new_node = temp;
  }

  return;
}

int main(int argc, char const *argv[])
{
  node *head = nullptr;

  insert_node(&head, 1, 11);
  insert_node(&head, 2, 22);
  insert_node(&head, 3, 33);
  insert_node(&head, 4, 44);
  insert_node(&head, 5, 55);

  while (head != nullptr)
  {
    cout << head->tag << " " << head->data << endl;
    head = head->next;
  }

  return 0;
}