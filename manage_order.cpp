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
  int id;
};

int id;

void insert_prioty_low(execution_staging_node **n, driver_priority priority,
                       UINTN Index,
                       EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler)
{

  execution_staging_node *temp = new (execution_staging_node);

  temp->Index = Index;
  temp->next = nullptr;
  temp->priority = priority;
  temp->cfhandler = cfhandler;
  temp->id = id++;
  execution_staging_node *head = *n;

  if (*n == nullptr)
  {
    (*n) = temp;
    return;
  }

  cout << "Low " << (*n)->id << endl;

  while ((*n)->next != nullptr)
  {
    (*n) = (*n)->next;
  }

  (*n)->next = temp;

  *n = head;

  return;
}

void insert_prioty_high(execution_staging_node **n, driver_priority priority,
                        UINTN Index,
                        EDKII_REDFISH_CONFIG_HANDLER_PROTOCOL *cfhandler)
{

  execution_staging_node *temp = new (execution_staging_node);

  temp->Index = Index;
  temp->next = nullptr;
  temp->priority = priority;
  temp->cfhandler = cfhandler;
  temp->id = id++;

  if (*n == nullptr)
  {
    (*n) = temp;
    return;
  }

  cout << "High " << (*n)->id << endl;

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
  execution_staging_node *prev;

  temp->Index = Index;
  temp->next = nullptr;
  temp->priority = priority;
  temp->cfhandler = cfhandler;
  temp->id = id++;

  int forward = 0;

  if (*n == nullptr)
  {
    (*n) = temp;
    return;
  }

  cout << "Mid " << (*n)->id << endl;

  while ((((*n)->priority == HIGH) || ((*n)->priority == MEDIUM)) &&
         ((*n)->next != nullptr))
  {
    prev = (*n);
    (*n) = (*n)->next;
    cout << "Mid next " << temp->id << " " << (*n)->id << endl;
    forward++;
  }

  if ((forward == 0) && ((*n)->priority == LOW))
  {
    temp->next = *n;
    *n = temp;
    return;
  }

  cout << "Here " << endl;
  /*
    if ((forward == 0) && (((*n)->priority == HIGH)) ||
        ((*n)->priority == LOW)) // *head == *n
    {
      (*n)->next = temp;
      return;
    }
    */

  if ((prev->next != nullptr) && forward)
  {
    mid = prev->next;
    prev->next = temp;
    temp->next = mid;
    *n = head;
    return;
  }

  if ((*n)->next == nullptr)
  {
    (*n)->next = temp;
    cout << "Inserted mod node here" << endl;
  }

  *n = head;

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

  if (EFI_ERROR(Status))
  {
    return;
  }

  for (Index = 0; Index < NumberOfHandles; Index++)
  {
    Status = gBs->HandleProtocol(Index, &ConfigHandler);

    driver_priority priority = cfg->GetPriority();

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

    cout << "Inserted " << n->id << " " << n->priority << endl;
  }

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
}

int main(int argc, char const *argv[])
{

  id = 0;
  driver_priority arr[] = {MEDIUM, LOW, LOW, HIGH, MEDIUM};

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
