#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *oddEvenList(ListNode *head) { return head; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  ListNode *head = new ListNode(103);

  obj->oddEvenList(head);

  return 0;
}
