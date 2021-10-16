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

pqueue *push_level_tree(stacks *top, pqueue *pqueue_head, bool child)
{
  pqueue *pqn = new pqueue();
  pqn->level = top->nodes->level;
  strcpy(pqn->name, top->nodes->name);
  strcpy(pqn->parent, top->nodes->parent);
  pqn->child = nullptr;
  pqn->sibling = nullptr;

  pqueue *head = nullptr;

  if (pqueue_head == nullptr)
  {
    pqueue_head = pqn;
    return pqueue_head;
  }
  else
  {
    head = pqueue_head;
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

    while (pqueue_head->child != nullptr)
    {
      pqueue_head = pqueue_head->child;
    }

    while (pqueue_head->sibling != nullptr)
    {
      pqueue_head = pqueue_head->sibling;
    }
    pqueue_head->sibling = pqn;
  }

  return head;
}

int main(int argc, char const *argv[])
{
  schema *head = nullptr;
  schema *prioritized = nullptr;
  stacks *top = nullptr;
  pqueue *pqueue_head = nullptr;

  head = create_schema(head);

  char name[30] = "none";

  return 0;
}