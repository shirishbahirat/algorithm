#include <iostream>

using namespace std;

typedef enum
{
  pass,
  fail
} EFI_STATUS;
typedef uint64_t EFI_HANDLE;
typedef uint16_t UINTN;

EFI_STATUS locateHandleBuffer(UINTN *Num)
{

  EFI_STATUS stat = pass;
  *Num = 5;
  return stat;
}

typedef enum _driver_priority
{
  HIGH,
  MEDIUM,
  LOW,
  UNDEFINED,
  PRIORITIES
} driver_priority;

typedef struct _ConfigHandler
{
  EFI_STATUS Init()
  {
    cout << "Init Function" << endl;
    EFI_STATUS stat = pass;
    return pass;
  };
  driver_priority GetPriority() { return priority; }
  driver_priority priority;
} EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL;

EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL Configs[5];

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
  cout << "check before address " << cfg->priority << endl;
  ConfigHandler = &cfg;

  cout << "check after address " << (*ConfigHandler)->priority << endl;

  EFI_STATUS stat = pass;
  return stat;
}

EFI_STATUS InstallProtocolInf(UINTN Indx,
                              EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL **cfhandler)
{
  EFI_STATUS stat = pass;
  return stat;
}

struct function_calls
{
  UINTN Init();
  driver_priority GetPriority();
};

struct execution_staging_node
{
  execution_staging_node *next;
  driver_priority priority;
  UINTN Index;
  EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler;
};

void insert_prioty_low(execution_staging_node **n, driver_priority priority,
                       UINTN Index,
                       EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler)
{

  execution_staging_node *temp = new (execution_staging_node);

  temp->Index = Index;
  temp->priority = priority;
  temp->cfhandler = cfhandler;

  if (*n == nullptr)
  {
    (*n) = temp;
    return;
  }

  while ((*n)->next == nullptr)
  {
    (*n) = (*n)->next;
  }

  (*n)->next = temp;

  return;
}

void insert_prioty_high(execution_staging_node **n, driver_priority priority,
                        UINTN Index,
                        EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler)
{

  execution_staging_node *temp = new (execution_staging_node);

  temp->Index = Index;
  temp->priority = priority;
  temp->cfhandler = cfhandler;

  if (*n == nullptr)
  {
    (*n) = temp;
    return;
  }

  temp->next = *n;

  *n = temp;
}

void insert_prioty_mid(execution_staging_node **n, driver_priority priority,
                       UINTN Index,
                       EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler)
{
  execution_staging_node *temp = new (execution_staging_node);
  execution_staging_node *head = *n;
  execution_staging_node *mid;

  temp->Index = Index;
  temp->priority = priority;
  temp->cfhandler = cfhandler;

  if (*n == nullptr)
  {
    (*n) = temp;
    return;
  }

  while (((*n)->priority == HIGH) && ((*n)->next != nullptr))
  {
    (*n) = (*n)->next;
  }

  if (head == *n)
  {
    temp->next = *n;

    *n = temp;
    return;
  }

  if ((*n)->next != nullptr)
  {
    mid = (*n)->next;
    (*n)->next = temp;
    temp->next = mid;
    return;
  }

  if ((*n)->next == nullptr)
  {
    (*n)->next = temp;
  }

  return;
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

  cout << "Numbe of Handles " << NumberOfHandles << endl;

  if (EFI_ERROR(Status))
  {
    return;
  }

  for (Index = 0; Index < NumberOfHandles; Index++)
  {
    Status = gBs->HandleProtocol(Index, &ConfigHandler);

    driver_priority priority = cfg->GetPriority();

    cout << Index << " " << priority << endl;

    switch (priority)
    {
    case HIGH:
      insert_prioty_high(&n, priority, Index, ConfigHandler);
      break;
    case MEDIUM:
      insert_prioty_mid(&n, priority, Index, ConfigHandler);
      break;
    case LOW:
      insert_prioty_low(&n, priority, Index, ConfigHandler);
      break;
    default:
      break;
    }
  }
  cout << "link list  " << n->priority << endl;
  cout << "link list  " << n->next->priority << endl;
  cout << "link list  " << n->next->next->priority << endl;
  cout << "link list  " << n->next->next->next->priority << endl;
  // cout << "link list  " << n->next->next->next->next->priority << endl;

  for (Index = 0; Index < NumberOfHandles - 1; Index++)
  {
    driver_priority priority = n->priority;
    UINTN Index = n->Index;
    EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler = n->cfhandler;
    cfhandler->Init();
    n = n->next;

    Status = gBs->InstallProtocolInterface(Index, &cfhandler);
  }
}

int main(int argc, char const *argv[])
{

  driver_priority arr[] = {LOW, MEDIUM, LOW, HIGH, HIGH};

  gBs = new (_gBs);
  gBs->LocateHandleBuffer = locateHandleBuffer;
  gBs->HandleProtocol = HndlProtocol;
  gBs->InstallProtocolInterface = InstallProtocolInf;

  execution_staging_node *head;

  for (int i = 0; i < 5; i++)
  {
    Configs[i].priority = arr[i];
  }

  RedfishConfigHandlerInitilization();

  return 0;
}
