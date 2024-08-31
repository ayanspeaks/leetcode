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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head; // If the list is empty, return the head

        int len = 1; // Initialize the length of the list as 1
        ListNode *newH, *tail;
        newH = tail = head; // Both newH and tail point to the head initially

        // Traverse the list to find the length and the tail node
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head; // Create a circular linked list by connecting the tail to the head

        k = k % len; // Calculate the effective number of rotations
        for (int i = 0; i < len - k; i++) tail = tail->next; // Move the tail pointer len-k steps forward
        
        newH = tail->next; // The new head is the next node after the tail
        tail->next = NULL; // Break the circular linked list by setting tail's next to NULL

        return newH; // Return the new head
    }
};
