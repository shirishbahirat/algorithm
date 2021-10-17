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

pqueue *generate_level_tree(pqueue *pqueue_head, schema *head)
{

  if (head == nullptr)
    return pqueue_head;

  pqueue *phead = pqueue_head, *temp = pqueue_head, *pqn = nullptr;

  if (pqueue_head == nullptr)
  {
    pqn = new pqueue();
    pqueue *prev = pqn;
    pqn->child = nullptr;
    pqn->sibling = nullptr;
    pqn->level = 0;
    strcpy(pqn->name, "head");
    strcpy(pqn->parent, "none");
    phead = pqn;
    pqueue_head = phead;

    cout << pqn->level << endl;

    for (int i = 1; i < 10; ++i)
    {
      pqn = new pqueue();
      prev->child = pqn;
      pqn->sibling = nullptr;
      pqn->level = i;
      cout << pqn->level << endl;
      strcpy(pqn->name, "head");
      strcpy(pqn->parent, "none");
      prev = pqn;
    }
  }

  while (head)
  {
    cout << head->level << " ";
    head = head->next;
  }
  cout << endl;

  return phead;
}

int main(int argc, char const *argv[])
{
  schema *head = nullptr;
  pqueue *pqueue_head = nullptr;

  head = create_schema(head);

  pqueue_head = generate_level_tree(pqueue_head, head);

  while (pqueue_head)
  {
    cout << pqueue_head->level << " ";
    pqueue_head = pqueue_head->child;
  }
  cout << endl;

  return 0;
}