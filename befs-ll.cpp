#include <cstdarg>
#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

struct stack
{
  node *n;
  stack *prev;
};

node *new_node(int data)
{

  node *n = new node();
  n->data = data;
  n->left = nullptr;
  n->left = nullptr;

  return n;
}

stack *push_stack(stack *s, node *n)
{

  stack *t = new stack();

  if (s == nullptr)
  {
    s = t;
    s->n = n;
    s->prev = nullptr;
    return s;
  }
  else
  {
    t->n = n;
    t->prev = s;
    s = t;
  }

  return s;
}

stack *t;

stack *pop_stack(stack *s)
{

  if (s == nullptr)
  {
    return s;
  }

  t = s;

  s = s->prev;

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

void dfs(stack *s, node *root)
{

  s = push_stack(s, root);

  while (s != nullptr)
  {
    stack *t = s;
    s = s->prev;
    if (t->n->right != nullptr)
    {
      s = push_stack(s, t->n->right);
    }
    if (t->n->left != nullptr)
    {
      s = push_stack(s, t->n->left);
    }
    cout << t->n->data << " ";
    delete t;
  }
  cout << endl;
}

int main(int argc, const char *argv[])
{

  stack *s = nullptr;

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