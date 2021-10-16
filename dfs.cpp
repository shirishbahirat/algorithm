#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

struct schema
{
  int level;
  char name[30];
  char parent[30];
  schema *next;
};

struct stacks
{
  schema *nodes;
  stacks *next;
};

struct pqueue
{
  int level;
  char name[30];
  char parent[30];
  pqueue *child;
  pqueue *sibling;
};

schema *split_line(string str, schema *sch)
{
  string word = "";
  int idx = 0;

  for (auto x : str)
  {
    if (x == ' ')
    {
      if (!idx)
      {
        sch->level = atoi(word.c_str());
      }
      else if (idx > 0)
      {
        strcpy(sch->name, word.c_str());
      }
      word = "";
      idx++;
    }
    else
    {
      word = word + x;
    }
  }

  strcpy(sch->parent, word.c_str());
  sch->next = nullptr;

  return sch;
}

schema *insert_schema(schema *head, schema *node)
{

  if (head == nullptr)
  {
    head = node;
    return head;
  }

  schema *temp = head;

  while (head->next != nullptr)
  {
    head = head->next;
  }

  head->next = node;
  head = temp;
  return head;
}

schema *create_schema(schema *head)
{

  schema *sch;

  ifstream file("schema.inf");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      sch = new schema();
      sch = split_line(line.c_str(), sch);
      head = insert_schema(head, sch);
    }
    file.close();
  }

  return head;
}

stacks *push_stack(stacks *top, schema *node)
{
  assert(node != nullptr);

  stacks *sp = new (stacks);
  sp->nodes = node;
  sp->next = nullptr;

  if (top == nullptr)
  {
    top = sp;
    return top;
  }

  sp->next = top;
  top = sp;

  return top;
}

stacks *pop_stack(stacks *top)
{
  assert(top != nullptr);

  stacks *temp = top;
  top = top->next;

  cout << "Poped from stack " << temp->nodes->name << endl;

  free(temp);

  return top;
}

stacks *push_level_to_stack(schema *head, int level, char *parent, stacks *top)
{

  while (head != nullptr)
  {
    if ((head->level == level) && (!strcmp(parent, head->parent)))
    {
      top = push_stack(top, head);
    }
    head = head->next;
  }

  return top;
}

pqueue *push_level_tree(stacks *top, pqueue *pqueue_head, bool child)
{
  pqueue *pqn = new pqueue();
  pqn->level = top->nodes->level;
  strcpy(pqn->name, top->nodes->name);
  strcpy(pqn->parent, top->nodes->parent);
  pqn->child = nullptr;
  pqn->sibling = nullptr;

  if (pqueue_head == nullptr)
  {
    pqueue_head = pqn;
  }

  if (child)
  {
    while (pqueue_head->child != nullptr)
    {
      pqueue_head = pqueue_head->child;
    }
    pqueue_head->child = pqn;
  }
  else
  {
    while (pqueue_head->sibling != nullptr)
    {
      pqueue_head = pqueue_head->sibling;
    }
    pqueue_head->sibling = pqn;
  }

  return pqueue_head;
}

int main(int argc, char const *argv[])
{
  schema *head = nullptr;
  schema *prioritized = nullptr;
  stacks *top = nullptr;
  pqueue *pqueue_head = nullptr;

  head = create_schema(head);

  char name[30] = "none";

  // insert root node
  top = push_level_to_stack(head, 0, name, top);
  pqueue_head = push_level_tree(top, pqueue_head, 0);
  top = pop_stack(top);

  // insert 1st child
  top = push_level_to_stack(head, 1, pqueue_head->name, top);
  pqueue_head = push_level_tree(top, pqueue_head, 1);
  top = pop_stack(top);

  cout << "after ins 1st child " << pqueue_head->name << endl;

  // insert 1st child
  // top = push_level_to_stack(head, 1, pqueue_head->name, top);
  // pqueue_head = push_level_tree(top, pqueue_head, 1);
  // top = pop_stack(top);

  while (head != nullptr)
  {
    cout << "node loop " << head->name << " " << head->level << " "
         << head->parent << endl;
    head = head->next;
  }

  while (top != nullptr)
  {
    cout << "stack loop " << top->nodes->name << " " << top->nodes->level << " "
         << top->nodes->parent << endl;
    top = top->next;
  }

  return 0;
}