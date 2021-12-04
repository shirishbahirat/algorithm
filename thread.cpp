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
    pthread_cond_wait(&cond, &lock);
  }
  pthread_cond_signal(&cond);

  pthread_mutex_unlock(&lock);

  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t thread_id;

  pthread_create(&thread_id, NULL, dispatcher_task, NULL);

  sleep(1);

  data = 0;

  pthread_join(thread_id, NULL);

  return 0;
}
