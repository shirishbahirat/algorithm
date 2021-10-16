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
  int name[30];
  int parent[30];
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

stacks *pop_stack(stacks *top, int level, string name)
{
  assert(top != nullptr);

  stacks *temp = top;
  top = top->next;

  cout << "Poped from stack " << temp->nodes->name << endl;

  free(temp);

  return top;
}

stacks *push_level(schema *head, int level, stacks *top)
{
  while (head != nullptr)
  {
    if (head->level == level)
      top = push_stack(top, head);
    head = head->next;
  }

  return top;
}

int main(int argc, char const *argv[])
{
  schema *head = nullptr;
  schema *prioritized = nullptr;
  stacks *top = nullptr;

  head = create_schema(head);

  top = push_level(head, 0, top);
  top = pop_stack(top, 0, "none");

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