/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Step 1: Find lengths of both lists
        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA) {
            lenA++;
            tempA = tempA->next;
        }

        while (tempB) {
            lenB++;
            tempB = tempB->next;
        }

        // Step 2: Align both pointers
        tempA = headA;
        tempB = headB;

        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) tempA = tempA->next;
        } else {
            int diff = lenB - lenA;
            while (diff--) tempB = tempB->next;
        }

        // Step 3: Move both pointers and compare
        while (tempA && tempB) {
            if (tempA == tempB) return tempA; // Found intersection
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr; // No intersection
    }
};
