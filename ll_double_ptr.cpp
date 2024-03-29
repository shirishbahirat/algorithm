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

void pop(node **head)
{

  if (*head == nullptr)
    return;

  if ((*head)->next == nullptr)
  {
    delete *head;
    return;
  }
  else
  {
    node *temp = *head;
    (*head) = (*head)->next;
    delete *head;
  }

  return;
}

int main(int argc, char const *argv[])
{

  node *head = nullptr;

  insert(&head, 0, 10);
  insert(&head, 1, 20);
  insert(&head, 2, 30);

  cout << head->next->next->data << endl;

  pop(&head);

  cout << head->data << endl;

  return 0;
}