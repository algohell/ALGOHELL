#include <stdlib.h>

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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    if (tempA == NULL || tempB == NULL)
      return NULL;
    // 길이 차이가 나니까 총 두바퀴를 돈다.
    // a가 null까지 도달하면 b의 head로, b가 null까지 도달하면 a의 head로.
    // 이렇게하면, 같은 부분이 있을 때 도달할 수 밖에 없음
    bool fA = true;
    bool fB = true;
    while (tempA != tempB)
    {
      tempA = tempA->next;
      tempB = tempB->next;
      if (fA && tempA == NULL)
      {
        tempA = headB;
        fA = false;
      }
      if (fB && tempB == NULL)
      {
        tempB = headA;
        fB = false;
      }
      // 하나가 NULL에 두 번째로 도달할 때 까지 같은게 없었으면 intersection이 없음
      if (!fA && tempA == NULL || !fB && tempB == NULL)
      {
        return NULL;
      }
    }
    return tempA;
  }
};