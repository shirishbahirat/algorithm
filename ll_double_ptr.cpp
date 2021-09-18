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
  node *n = new node(1, 10);

  if (*head == nullptr)
  {
    *head = n;
  }
}

int main(int argc, char const *argv[])
{

  node *head = nullptr;

  insert(&head, 1, 2);

  cout << head->data << endl;

  return 0;
}