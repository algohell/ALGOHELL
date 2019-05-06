using namespace std;

class Solution
{
public:
  // 나눈 뒤 병합
  ListNode *sortList(ListNode *head)
  {
    if (!head || !head->next)
    {
      return head;
    }
    ListNode *slow = head, *fast = head->next;
    // fast는 두번씩, slow는 한번씩 가서 리스트의 중앙을 잡는다
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *r = slow->next;
    slow->next = NULL;
    // 재귀적으로 반복
    return merge(sortList(head), sortList(r));
  }

private:
  // 오른쪽 왼쪽 비교해서 정렬
  ListNode *merge(ListNode *l, ListNode *r)
  {
    if (!l || !r)
    {
      return l ? l : r;
    }
    if (l->val < r->val)
    {
      l->next = merge(l->next, r);
      return l;
    }
    r->next = merge(l, r->next);
    return r;
  }
};