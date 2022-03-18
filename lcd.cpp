#include <iostream>

using namespace std;

struct node
{
  int val;
  node *left;
  node *right;
  node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main(int argc, char *argv[]) { return 0; }