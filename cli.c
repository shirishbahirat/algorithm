#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct _mgmet
{
  pthread_cond_t cond;
  pthread_mutex_t lock;
} mgmet;

mgmet management = {.cond = PTHREAD_COND_INITIALIZER,
                    .lock = PTHREAD_MUTEX_INITIALIZER};

void execute_command(char *command)
{

  char cm[] = "shirish";

  if (!strcmp(command, cm))
  {
    printf("Set data %s\n", command);
  }

  return;
}

char data[20];

void *dispatcher_task()
{

  while (1)
  {
    pthread_mutex_lock(&management.lock);
    while (1)
    {
      pthread_cond_wait(&management.cond, &management.lock);
    }
    pthread_cond_signal(&management.cond);

    pthread_mutex_unlock(&management.lock);
  }

  return NULL;
}

void *cli_task()
{

  while (1)
  {
    printf(">> ");
    pthread_mutex_lock(&management.lock);
    pthread_cond_signal(&management.cond);
    pthread_mutex_unlock(&management.lock);
    scanf("%[^\n]s", data);
    execute_command(data);
  }

  return NULL;
}

int main(int argc, char *argv[])
{

  pthread_t thread_idx, thread_idy;

  pthread_create(&thread_idx, NULL, dispatcher_task, NULL);
  pthread_create(&thread_idy, NULL, cli_task, NULL);

  pthread_join(thread_idx, NULL);
  pthread_join(thread_idy, NULL);
  return 0;
}