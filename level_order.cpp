#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

typedef enum
{
  pass,
  fail
} EFI_STATUS;
typedef uint64_t EFI_HANDLE;
typedef uint16_t UINTN;
typedef uint16_t DRIVER_LEVEL;

struct schema
{
  int level;
  char name[30];
  char parent[30];
  schema *next;
};

#define DEFAULT_LEVELS 10
uint16_t current_levels = 0;

typedef struct _ConfigHandler
{
  EFI_STATUS Init()
  {
    cout << " Init ";
    EFI_STATUS stat = pass;
    return pass;
  };

  DRIVER_LEVEL GetLevel() { return level; }
  char *GetName() { return name; }
  char *GetPerent() { return parent; }

  DRIVER_LEVEL level;
  char name[30];
  char parent[30];

} EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL;

struct pqueue
{
  int level;
  char name[30];
  char parent[30];
  UINTN Index;
  pqueue *child;
  pqueue *sibling;
  EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfghandler;
};

schema *create_schema_temp(schema *schema_head, int *number_of_drivers);

schema *schema_head = nullptr;
pqueue *pqueue_head = nullptr;

EFI_STATUS locateHandleBuffer(UINTN *Num)
{

  EFI_STATUS stat = pass;
  int number_of_drivers = 0;

  schema_head = create_schema_temp(schema_head, &number_of_drivers);

  *Num = number_of_drivers;
  return stat;
}

EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL Configs[30];

int EFI_ERROR(EFI_STATUS stat) { return stat; }

struct _gBs
{
  EFI_STATUS (*LocateHandleBuffer)(UINTN *);
  EFI_STATUS (*HandleProtocol)(UINTN, EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL **);
  EFI_STATUS(*InstallProtocolInterface)
  (UINTN, EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL **);
};

_gBs *gBs;
EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfg;

EFI_STATUS HndlProtocol(UINTN Index,
                        EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL **ConfigHandler)
{
  cfg = &Configs[Index];

  cfg->level = schema_head->level;
  strcpy(cfg->name, schema_head->name);
  strcpy(cfg->parent, schema_head->parent);

  schema_head = schema_head->next;

  ConfigHandler = &cfg;
  EFI_STATUS stat = pass;
  return stat;
}

EFI_STATUS InstallProtocolInf(UINTN Indx,
                              EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL **cfhandler)
{
  EFI_STATUS stat = pass;
  return stat;
}

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

struct execution_staging_node
{
  execution_staging_node *next;
  DRIVER_LEVEL level;
  UINTN Index;
  EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfghandler;
  int id;
};

schema *insert_schema_to_llist_temp(schema *schema_head, schema *node)
{

  if (schema_head == nullptr)
  {
    schema_head = node;
    return schema_head;
  }

  schema *temp = schema_head;

  while (schema_head->next != nullptr)
  {
    schema_head = schema_head->next;
  }

  schema_head->next = node;
  schema_head = temp;
  return schema_head;
}

schema *create_schema_temp(schema *schema_head, int *number_of_drivers)
{

  schema *sch;
  int num = 0;

  ifstream file("schema.inf");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      sch = new schema();
      sch = split_line(line.c_str(), sch);
      schema_head = insert_schema_to_llist_temp(schema_head, sch);
      num++;
    }
    file.close();
  }

  *number_of_drivers = num;

  return schema_head;
}

pqueue *generate_level_tree(pqueue *pqueue_head, schema *schema_head)
{

  if (schema_head == nullptr)
    return pqueue_head;

  pqueue *phead = pqueue_head, *temp = pqueue_head, *pqn = nullptr;

  if (pqueue_head == nullptr)
  {
    pqn = new pqueue();
    pqueue *prev = pqn;
    pqn->child = nullptr;
    pqn->sibling = nullptr;
    pqn->level = 0;
    strcpy(pqn->name, "schema_head");
    strcpy(pqn->parent, "none");
    phead = pqn;
    pqn->cfghandler = nullptr;
    pqueue_head = phead;

    cout << pqn->level << endl;

    for (int i = 1; i < 10; ++i)
    {
      pqn = new pqueue();
      prev->child = pqn;
      pqn->sibling = nullptr;
      pqn->level = i;
      cout << pqn->level << endl;
      strcpy(pqn->name, "schema_head");
      strcpy(pqn->parent, "none");
      pqn->cfghandler = nullptr;
      prev = pqn;
    }
  }

  while (schema_head)
  {
    cout << schema_head->level << " ";
    int level = schema_head->level;
    temp = pqueue_head;

    while (level)
    {
      temp = temp->child;
      level--;
    }
    cout << " after while loop " << temp->level << endl;

    while (temp->sibling)
    {
      temp = temp->sibling;
    }

    pqn = new pqueue();
    strcpy(pqn->name, schema_head->name);
    strcpy(pqn->parent, schema_head->parent);
    pqn->level = schema_head->level;
    pqn->cfghandler = nullptr;
    temp->sibling = pqn;

    schema_head = schema_head->next;
  }
  cout << endl;

  return phead;
}

pqueue *insert_level_tree(pqueue *pqueue_head, char *name, char *parent,
                          DRIVER_LEVEL level, UINTN Index,
                          EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *ConfigHandler)
{

  pqueue *phead = pqueue_head, *temp = pqueue_head, *pqn = nullptr;

  if (pqueue_head == nullptr)
  {
    pqn = new pqueue();
    pqueue *prev = pqn;
    pqn->child = nullptr;
    pqn->sibling = nullptr;
    pqn->level = 0;
    strcpy(pqn->name, "schema_head");
    strcpy(pqn->parent, "none");
    pqn->cfghandler = nullptr;
    phead = pqn;
    pqueue_head = phead;

    cout << pqn->level << endl;

    for (int i = 1; i < DEFAULT_LEVELS; ++i)
    {
      pqn = new pqueue();
      prev->child = pqn;
      pqn->sibling = nullptr;
      pqn->level = i;
      strcpy(pqn->name, "schema_head");
      strcpy(pqn->parent, "none");
      pqn->cfghandler = nullptr;
      prev = pqn;
    }

    current_levels = DEFAULT_LEVELS;
  }

  if (level > current_levels)
  {

    pqn = pqueue_head;
    for (int i = 0; i < current_levels; ++i)
    {
      pqn = pqn->child;
    }

    for (int i = current_levels; < level; ++i)
    {
      pqn = new pqueue();
      prev->child = pqn;
      pqn->sibling = nullptr;
      pqn->level = i;
      strcpy(pqn->name, "schema_head");
      strcpy(pqn->parent, "none");
      pqn->cfghandler = nullptr;
      prev = pqn;
    }

    current_levels = level;
  }

  temp = pqueue_head;

  while (level)
  {
    temp = temp->child;
    level--;
  }

  while (temp->sibling)
  {
    temp = temp->sibling;
  }

  pqn = new pqueue();
  strcpy(pqn->name, name);
  strcpy(pqn->parent, parent);
  pqn->level = level;
  pqn->Index = Index;
  pqn->cfghandler = ConfigHandler;
  temp->sibling = pqn;

  return phead;
}

EFI_STATUS execution_order_per_level(pqueue *pqueue_head)
{

  EFI_STATUS Status = fail;

  if (pqueue_head == nullptr)
    return Status;

  pqueue *temp;

  while (pqueue_head)
  {
    cout << pqueue_head->level << " ";

    temp = pqueue_head;
    while (temp)
    {
      cout << temp->name << " ";
      if (temp->cfghandler)
      {
        temp->cfghandler->Init();
      }
      cout << " " << temp->parent << endl;
      temp = temp->sibling;
    }
    cout << endl;

    pqueue_head = pqueue_head->child;
  }
  cout << endl;

  Status = pass;

  return Status;
}

void RedfishConfigHandlerInitilization(void)
{
  EFI_STATUS Status;
  EFI_HANDLE *HandleBuffer;
  UINTN NumberOfHandles;
  EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *ConfigHandler;
  UINTN Index;
  execution_staging_node *n = nullptr;

  Status = gBs->LocateHandleBuffer(&NumberOfHandles);

  cout << NumberOfHandles << endl;

  if (EFI_ERROR(Status))
  {
    return;
  }

  for (Index = 0; Index < NumberOfHandles; Index++)
  {
    Status = gBs->HandleProtocol(Index, &ConfigHandler);
    pqueue_head =
        insert_level_tree(pqueue_head, cfg->GetName(), cfg->GetPerent(),
                          cfg->GetLevel(), Index, ConfigHandler);
  }

  Status = execution_order_per_level(pqueue_head);

  /*
    for (Index = 0; Index < NumberOfHandles; Index++)
    {
      driver_priority priority = n->priority;
      UINTN Tdx = n->Index;
      EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler = n->cfhandler;
      cout << Index << " " << priority << endl;
      cfhandler->Init();
      n = n->next;
      Status = gBs->InstallProtocolInterface(Tdx, &cfhandler);
    }
    */
}

int main(int argc, char const *argv[])
{

  int number_of_drivers;

  gBs = new (_gBs);
  gBs->LocateHandleBuffer = locateHandleBuffer;
  gBs->HandleProtocol = HndlProtocol;
  gBs->InstallProtocolInterface = InstallProtocolInf;

  RedfishConfigHandlerInitilization();

  /*

  schema_head = create_schema_temp(schema_head, &number_of_drivers);

  pqueue_head = generate_level_tree(pqueue_head, schema_head);

  execute_per_level(pqueue_head);

  cout << number_of_drivers << endl;
  */

  return 0;
}