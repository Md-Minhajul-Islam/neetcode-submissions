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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(-1);
        ListNode* currDummy = dummy;

        ListNode* curr = head;
        while(head)
        {
            int cnt = 0;
            while(cnt < k && curr)
            {
                curr = curr->next;
                cnt++;
            }

            if(cnt == k)
            {
                curr = head;
                ListNode* prev = nullptr;
                cnt = 0;
                while(cnt < k)
                {
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                    cnt++;
                }
                currDummy->next = prev;
                currDummy = head;
                head = curr;
            }
            else
            {
                currDummy->next = head;
                break;
            }
        }
        return dummy->next;
    }
};
