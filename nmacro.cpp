#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
} NODE_V2;

#define ID(version) "NODE_##V"

int main(int argc, char const *argv[])
{

  cout << ID(2) << endl;

  return 0;
}