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

void push_stack(stacks *top, schema *node) { assert(node != nullptr); }

int main(int argc, char const *argv[])
{
  schema *head = nullptr;
  schema *prioritized = nullptr;
  stacks *top = nullptr;

  head = create_schema(head);

  while (head != nullptr)
  {
    cout << "node loop " << head->name << " " << head->level << " "
         << head->parent << endl;
    head = head->next;
  }

  push_stack(top, head);

  return 0;
}