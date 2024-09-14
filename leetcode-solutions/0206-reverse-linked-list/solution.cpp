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
    ListNode* reverseList(ListNode* head) {
        /*
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
        */

        ListNode* temp=head;
        stack<int>st;
        while(temp)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};
