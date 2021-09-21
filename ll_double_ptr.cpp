#include <iostream>

using namespace std;

struct node
{
  int data;
  int tag;
  node *next;
  node(int t, int d) : data(d), tag(t), next(nullptr) {}
};

void insert(node **head, int tag, int data)
{
  node *n = new node(tag, data);
  node *tmp = *head;

  if (*head == nullptr)
  {
    *head = n;
    return;
  }
  else
  {
    while ((*head)->next != nullptr)
    {
      (*head) = (*head)->next;
    }
    (*head)->next = n;
    *head = tmp;
  }
}

int main(int argc, char const *argv[])
{

  node *head = nullptr;

  insert(&head, 1, 2);
  insert(&head, 2, 3);
  insert(&head, 3, 4);

  cout << head->next->next->data << endl;

  return 0;
}