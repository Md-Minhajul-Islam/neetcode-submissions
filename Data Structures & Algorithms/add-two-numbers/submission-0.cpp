/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        int rem = 0;
        while(l1 && l2)
        {
            int sum = l1->val+l2->val+rem;
            ListNode* node = new ListNode(sum%10);
            rem = sum/10;
            curr->next = node;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int sum = l1->val+rem;
            ListNode* node = new ListNode(sum%10);
            rem = sum/10;
            curr->next = node;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int sum = l2->val+rem;
            ListNode* node = new ListNode(sum%10);
            rem = sum/10;
            curr->next = node;
            curr = curr->next;
            l2 = l2->next;
        }
        if(rem)
        {
            ListNode* node = new ListNode(rem);
            curr->next = node;
        }
        return dummyHead->next;
    }
};
