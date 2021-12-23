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

int main(int argc, char const *argv[])
{

  node *cmd = new node();

  return 0;
}