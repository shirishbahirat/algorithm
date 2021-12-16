#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <time.h>

void delay(int sec)
{
  int ms = 1000 * sec;

  clock_t st = clock();

  while (clock() < st + ms)
  {
  }
}

pthread_cond_t cond;
pthread_mutex_t lock;

int data = 0;

void *producer()
{

  while (1)
  {
    while (data == 0)
    {
      data = 1;
      delay(10);
      pthread_mutex_lock(&lock);
    }
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    printf("Out of 0\n");
  }

  return NULL;
}

void *consumer()
{

  while (1)
  {
    while (data == 1)
    {
      data = 0;
      delay(10);
      pthread_mutex_lock(&lock);
    }
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    printf("Out of 1\n");
  }

  return NULL;
}

int main(int argc, char const *argv[])
{

  pthread_t idx, idy;

  pthread_create(&idx, NULL, producer, NULL);
  pthread_create(&idy, NULL, consumer, NULL);

  pthread_join(idx, NULL);
  pthread_join(idy, NULL);

  return 0;
}