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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int val = 1;

    ListNode *temp = nullptr;
    ListNode *list = head;

    while (head)
    {
      val++;

      if (val == n)
      {
        temp = head;
      }

      head = head->next;

      if (val > n)
      {
        temp = temp->next;
      }
    }

    return list;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
