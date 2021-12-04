#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

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
    pthread_mutex_lock(&lock);
    while (1)
    {
      pthread_cond_wait(&cond, &lock);
    }
    pthread_cond_signal(&cond);

    pthread_mutex_unlock(&lock);
  }

  return NULL;
}

void *cli_task()
{

  while (1)
  {
    printf(">>");
    scanf("%19s", data);
    pthread_mutex_lock(&lock);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
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
