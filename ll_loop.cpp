#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && slow && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow)
        return true;
    }

    return false;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
