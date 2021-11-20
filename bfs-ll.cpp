#include <cstdarg>
#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

struct queue
{
  node *n;
  queue *next;
};

node *new_node(int data)
{

  node *n = new node();
  n->data = data;
  n->left = nullptr;
  n->left = nullptr;

  return n;
}

queue *push_queue(queue *s, node *n)
{

  queue *t = new queue();
  queue *head = s;

  if (s == nullptr)
  {
    s = t;
    s->n = n;
    s->next = nullptr;
    return s;
  }
  else
  {

    while (s->next)
    {
      s = s->next;
    }

    t->next = nullptr;
    s->next = t;
    t->n = n;
  }

  return head;
}

queue *t;

queue *pop_queue(queue *s)
{

  if (s == nullptr)
  {
    return s;
  }

  t = s;

  s = s->next;

  return t;
}

void post_order(node *n)
{

  if (n == nullptr)
    return;

  post_order(n->left);
  post_order(n->right);
  cout << n->data << " ";
}

void in_order(node *n)
{

  if (n == nullptr)
    return;

  in_order(n->left);
  cout << n->data << " ";
  in_order(n->right);
}

void pre_order(node *n)
{

  if (n == nullptr)
    return;

  cout << n->data << " ";
  pre_order(n->left);
  pre_order(n->right);
}

void dfs(queue *s, node *root)
{

  s = push_queue(s, root);

  while (s != nullptr)
  {
    queue *t = s;
    s = s->next;
    if (t->n->right != nullptr)
    {
      s = push_queue(s, t->n->right);
    }
    if (t->n->left != nullptr)
    {
      s = push_queue(s, t->n->left);
    }
    cout << t->n->data << " ";
    delete t;
  }
  cout << endl;
}

int main(int argc, const char *argv[])
{

  queue *s = nullptr;

  node *root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(3);
  root->left->left = new_node(4);
  root->left->right = new_node(5);
  root->right->left = new_node(6);
  root->right->right = new_node(7);

  in_order(root);
  cout << endl;

  pre_order(root);
  cout << endl;

  post_order(root);
  cout << endl;

  dfs(s, root);

  return 0;
}