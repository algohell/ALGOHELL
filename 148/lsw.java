/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
import java.util.Arrays;

class Solution {
    public ListNode sortList(ListNode head) {
        int len = 0;
        ListNode temp;
        for (temp = head; temp != null; temp = temp.next) {
            len++;
        }
        
        temp = head;
        int[] arr = new int[len];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = temp.val;
            temp = temp.next;
        }
        
        temp = head;
        Arrays.sort(arr);
        for (int value : arr) {
            temp.val = value;
            temp = temp.next;
        }
        return head;
    }
}