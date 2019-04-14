/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

import java.util.Set;
import java.util.HashSet;

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> set = new HashSet<>();		// node의 주소는 겹치지 않는다
        ListNode temp = null;
        
        for (temp = headA; temp != null; temp = temp.next) {
            set.add(temp);	// headA의 node의 주소를 set에 담는다
        }
        for (temp = headB; temp != null; temp = temp.next) {
            if (set.contains(temp)) {	// headB 리스트 중에 headA의 node의 주소가 있다면 선택
                break;
            }
        }
        
        return temp;		// 겹치는 게 없으면 null 반환
    }
}
