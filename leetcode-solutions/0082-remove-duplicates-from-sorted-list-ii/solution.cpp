/**
 * Definition for singly-linked list.
 * struct ListNode 
 {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* slow=head;
        while(slow)
        {
            if(slow->next!=NULL&&(slow->val==slow->next->val))
            {
                while(slow->next!=NULL&& slow->val==slow->next->val)
                {
                    slow=slow->next;
                }
                prev->next=slow->next;
            }
            else
            {
                prev=prev->next;
            }
            slow=slow->next;

        }
        return dummy->next;

        
        
        
    }
};
