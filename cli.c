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

int main(int argc, char *argv[]) { return 0; }