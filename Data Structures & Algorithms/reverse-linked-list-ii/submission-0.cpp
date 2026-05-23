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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        int pos = 0;
        ListNode *curr = head, *prev = nullptr;
        ListNode *left = nullptr, *right = nullptr, *leftLeft = nullptr, *rightRight = nullptr;


        while(curr)
        {
            ++pos;
            
            if(pos == l-1) leftLeft = curr;
            if(pos == l) left = curr;
            if(pos == r) right = curr;
            if(pos == r+1) rightRight = curr;

            if(pos >= l && pos <= r)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            else curr = curr->next;
        }

        if(left) left->next = rightRight;
        if(leftLeft) leftLeft->next = right;

        if(leftLeft == nullptr) head = right;

        return head;
    }
};