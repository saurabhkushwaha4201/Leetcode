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
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        ListNode* dummyNode = new ListNode(-1); // Dummy node to simplify the code
        ListNode* curr = dummyNode; // Pointer to traverse the result list

        int carry = 0; // Initialize carry to 0

        // Loop until both lists are exhausted
        while (num1 != NULL || num2 != NULL) {
            int sum = 0; // Initialize sum for this iteration

            // Add data from num1 if available
            if (num1) {
                sum = sum + num1->val;
                num1 = num1->next;
            }

            // Add data from num2 if available
            if (num2) {
                sum = sum + num2->val;
                num2 = num2->next;
            }

            // Add carry from previous iteration
            sum += carry;
            carry = sum / 10; // Update carry for next iteration

            // Create new node with the digit value (sum % 10)
            ListNode* newNode = new ListNode(sum % 10);

            // Link the new node to the result list
            curr->next = newNode;
            curr = curr->next; // Move to the next node
        }

        // If there is any carry left, add a new node with carry value
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        // Return the next of dummy node which is the head of the result list
        return (dummyNode->next);
    }
};
