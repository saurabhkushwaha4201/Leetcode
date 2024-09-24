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
    ListNode* reverseList(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward;
        while (curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        head=prev;
        return head;
    }
    ListNode* doubleIt(ListNode* head) 
    {
        reverseList(head);
        ListNode* temp=head;
        int carry=0;
        while(temp)
        {
            int sum = temp->val * 2 + carry; // Calculate the sum including carry
            temp->val = sum % 10; // Update the current node's value
            carry = sum / 10; // Update carry for next node
            temp = temp->next; // Move to the next node
        }
        reverseList(head);
        if(carry>0)
        {
            ListNode* new_Node=new ListNode(carry);
            new_Node->next=head;
            head=new_Node;
        }
        
        return head;
    }
};
