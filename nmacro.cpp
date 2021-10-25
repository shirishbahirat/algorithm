#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
} NODE_V2_CS;

#define ID(version) (NODE_V##version##_CS).data
#define PID(version) (PNODE_V##version##_CS)->data

char ride[] = "\
	\"Boot\":\"Disabled\",\
	\"values\" : [\"once\",\"Disabled\"]";

int main(int argc, char const *argv[])
{

  NODE_V2_CS.data = 2;

  node *PNODE_V2_CS = &NODE_V2_CS;

  ID(2) = 4;
  PID(2) = 10;

  cout << NODE_V2_CS.data << endl;

  return 0;
}