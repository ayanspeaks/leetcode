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
    bool hasCycle(ListNode *head) {
        // If the list is empty or has only one node, it cannot have a cycle.
        if (head == NULL || head->next == NULL)
            return false;
        // Initialize two pointers, slow and fast.
        ListNode *slow = head;
        ListNode *fast = head;
        // Traverse the list with the two pointers.
        // Fast pointer moves two steps at a time, slow pointer moves one step.
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            // If slow and fast pointers meet, there is a cycle.
            if (slow == fast) {
                return true;
            }
        }
        // If the loop exits, no cycle is detected.
        return false;
    }
};
