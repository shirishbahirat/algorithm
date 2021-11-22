#include <iostream>

using namespace std;

struct queue
{
  int data;
  queue *next;
};

int main(int argc, char const *argv[])
{

  queue q;

  (&q)->data = 10;

  cout << q.data << endl;

  return 0;
}