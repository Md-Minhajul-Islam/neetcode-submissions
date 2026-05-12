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
        List<ListNode> nodes = new List<ListNode>();

        ListNode curr = head;
        while(curr != null)
        {
            nodes.Add(curr);
            curr = curr.next;
        }

        int i = nodes.Count-n;
        if (i == 0)
        {
            return head.next;
        }
        else
        {
            nodes[i-1].next = nodes[i].next;
        }

        return head;
    }
}
