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
    public bool HasCycle(ListNode head) {
        
        if(head == null) return false;
        
        ListNode hare = head.next;
        ListNode tortoise = head;

        while(hare != null)
        {
            if(hare.next != null) hare = hare.next.next;
            else return false;

            tortoise = tortoise.next;

            if(hare == tortoise) return true;
        }
        return false;
    }
}
