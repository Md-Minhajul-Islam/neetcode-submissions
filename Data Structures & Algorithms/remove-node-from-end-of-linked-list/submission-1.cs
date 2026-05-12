/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        
        ListNode curr = head;
        int cnt = 0;
        while(curr != null)
        {
            cnt++;
            curr = curr.next;
        }

        int j = cnt-n;

        if(j == 0) return head.next;

        int i = 1;
        curr = head;
        while(curr != null)
        {
            if(i == j)
            {
                curr.next = curr.next.next;
                break;
            }
            i++;
            curr = curr.next;
        }

        return head;
    }
}
