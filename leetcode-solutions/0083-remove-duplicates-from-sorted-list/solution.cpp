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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* temp=head;
        ListNode* forward=head->next;
        while(forward)
        {
            if(temp->val==forward->val)
            {
                forward=forward->next;
            }
            else
            {
                temp->next=forward;
                temp=forward;
                forward=forward->next;
            }
        }
        temp->next=forward;
        temp=forward;
        return head;
        
    }
};
