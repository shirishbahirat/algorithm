#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

char data = 'a';

void *dispatcher_task()
{

  while (1)
  {
    pthread_mutex_lock(&lock);
    while (data)
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
    scanf("%c", &data);

    printf("Set data %c\n", data);
    pthread_mutex_lock(&lock);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
  }

  return NULL;
}
int main(int argc, char *argv[])
{
  pthread_t thread_idx, thread_idy;

  pthread_create(&thread_idx, NULL, dispatcher_task, NULL);
  pthread_create(&thread_idy, NULL, cli_task, NULL);
  printf("created thread\n");

  pthread_join(thread_idx, NULL);
  pthread_join(thread_idy, NULL);

  return 0;
}
