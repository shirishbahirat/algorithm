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
    tail = cmd;
  }
  else
  {
    head->next = cmd;
    cmd->prev = head;
    if (tail->next == nullptr)
    {
      tail->next = cmd;
    }
  }

  head = cmd;

  return head;
}

node *pop(node *cmd)
{

  if (tail == nullptr)
  {
    return nullptr;
  }

  node *temp = tail;

  tail = tail->next;

  return temp;
}

int main(int argc, char const *argv[])
{

  node *cmd = nullptr;

  cmd = new node(10);
  head = push(cmd);
  cout << tail->data << endl;
  cmd = new node(11);
  head = push(cmd);
  cout << tail->data << endl;
  cmd = new node(12);
  head = push(cmd);
  cout << tail->data << endl;

  cout << head->data << " " << head->prev->data << " " << head->prev->prev->data
       << endl;

  return 0;
}