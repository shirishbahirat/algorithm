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
}

void inser_schema(schema **sch) {}

int main(int argc, char const *argv[]) { return 0; }