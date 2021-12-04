#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int data = 1;

void *dispatcher_task()
{

  pthread_mutex_lock(&lock);
  while (data)
  {
    printf("Waiting for cond\n");
    pthread_cond_wait(&cond, &lock);
  }
  pthread_cond_signal(&cond);
  printf("Trigged cond\n");

  pthread_mutex_unlock(&lock);
  printf("Existing thread\n");

  return NULL;
}

void *cli_task()
{

  printf(">>");
  scanf("%d", &data);

  printf("Set data\n");
  pthread_mutex_lock(&lock);
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&lock);
  printf("Triggered condition\n");

  return NULL;
}
int main(int argc, char *argv[])
{
  pthread_t thread_idx, thread_idy;

  pthread_create(&thread_idx, NULL, dispatcher_task, NULL);
  pthread_create(&thread_idy, NULL, cli_task, NULL);
  printf("created thread\n");

  sleep(1);
  printf("Timer done\n");

  pthread_join(thread_idx, NULL);
  pthread_join(thread_idy, NULL);

  return 0;
}
