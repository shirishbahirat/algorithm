#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
} NODE_V2_CS;

#define ID(version) (NODE_V##version##_CS).data

int main(int argc, char const *argv[])
{

  NODE_V2_CS.data = 2;

  ID(2) = 4;

  cout << NODE_V2_CS.data << endl;

  return 0;
}