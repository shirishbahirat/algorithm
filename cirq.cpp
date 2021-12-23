#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
  node *prev;

  node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

node *head = nullptr;
node *tail = nullptr;

node *push(node *cmd);
node *pop(node *cmd);

node *push(node *cmd)
{
  if (head == nullptr)
  {
    head = cmd;
  }
  else
  {
    head->next = cmd;
    cmd->prev = head;
  }

  head = cmd;

  return head;
}

int main(int argc, char const *argv[])
{

  node *cmd = new node(10);

  return 0;
}