#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

pthread_cond_t cond;
pthread_mutex_t lock;

int data = 0;

void *producer() { return NULL; }

void *consumer() { return NULL; }

int main(int argc, char const *argv[])
{

  pthread_t idx, idy;

  pthread_create(&idx, NULL, producer, NULL);
  pthread_create(&idy, NULL, consumer, NULL);

  pthread_join(idx, NULL);
  pthread_join(idy, NULL);

  return 0;
}