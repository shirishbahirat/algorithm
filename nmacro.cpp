#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
} NODE_V2_CS;

#define ID(version) (NODE_##V_CS).data

int main(int argc, char const *argv[])
{

  NODE_V2_CS.data = 2;
  cout << ID(2) << endl;

  return 0;
}