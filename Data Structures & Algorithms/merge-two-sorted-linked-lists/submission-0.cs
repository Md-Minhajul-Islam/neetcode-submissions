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
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {

        ListNode dummy = new ListNode(-1000, null);
        ListNode curr = dummy;

        while(list1 != null && list2 != null)
        {
            if(list1.val <= list2.val)
            {
                curr.next = list1;
                list1 = list1.next;
            }
            else
            {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }

        while(list1 != null)
        {
            curr.next = list1;
            list1 = list1.next;
            curr = curr.next;
        }

        while(list2 != null)
        {
            curr.next = list2;
            list2 = list2.next;
            curr = curr.next;
        }
        return dummy.next;
    }
}