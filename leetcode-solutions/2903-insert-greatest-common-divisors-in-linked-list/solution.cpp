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
    int gcd(int a, int b) {
        // Base case: if b is 0, the GCD is a
        if (b == 0) {
            return a;
        }
        // Recursive case: GCD of b and a % b
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        int gcdvalue;
        while (temp2 != NULL) {
            gcdvalue = gcd(temp1->val, temp2->val);
            ListNode* gcdNode = new ListNode(gcdvalue);
            temp1->next = gcdNode;
            gcdNode->next = temp2;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return head;
    }
};
