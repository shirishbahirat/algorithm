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

void insert_node(node **new_node, int data, int tag)
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

  insert_node(&head, 10, 1);
  insert_node(&head, 11, 2);
  insert_node(&head, 12, 3);
  insert_node(&head, 13, 4);
  insert_node(&head, 14, 5);

  cout << head->tag << endl;
  cout << head->next->tag << endl;
  cout << head->next->next->tag << endl;
  cout << head->next->next->next->tag << endl;
  cout << head->next->next->next->next->tag << endl;

  return 0;
}