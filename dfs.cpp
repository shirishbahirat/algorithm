#include <iostream>

struct schema
{
  int level;
  char *name;
  char *parent;
  schema *next;
  bool mapped;
};

schema *create_node(int level, char *name, char *parent)
{
  schema *node = new schema();
  node->level = level;
  node->name = name;
  node->parent = parent;
  node->next = nullptr;
  node->mapped = false;

  return node;
}

int level[] = {};
char *name[] = {};
char *parent[] = {"Root", "Boot", "Systems"};

void inser_schema(schema **sch) {}

int main(int argc, char const *argv[]) { return 0; }