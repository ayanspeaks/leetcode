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
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or contains only one node, return head
        if (!head || !head->next) {
            return head;
        }

        // Helper function to merge two sorted lists
        auto merge = [](ListNode* left, ListNode* right) -> ListNode* {
            ListNode dummy(0); // Dummy node to start the merged list
            ListNode* curr = &dummy; // Pointer to the current node in the merged list

            // Merge the two lists
            while (left && right) {
                if (left->val <= right->val) {
                    curr->next = left;
                    left = left->next;
                } else {
                    curr->next = right;
                    right = right->next;
                }
                curr = curr->next;
            }

            // Attach the remaining nodes, if any
            curr->next = left ? left : right;

            return dummy.next; // Return the merged list, skipping the dummy node
        };

        // Helper function to find the middle of the list
        auto findMiddle = [](ListNode* node) -> ListNode* {
            ListNode* slow = node;
            ListNode* fast = node->next;

            // Move slow pointer by one step and fast pointer by two steps
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow; // Slow pointer now points to the middle node
        };

        // Find the middle of the list
        ListNode* mid = findMiddle(head);
        ListNode* rightHead = mid->next; // Start of the right half
        mid->next = nullptr; // Split the list into two halves

        // Recursively sort the left and right halves
        ListNode* sortedLeft = sortList(head);
        ListNode* sortedRight = sortList(rightHead);

        // Merge the sorted halves and return the merged list
        return merge(sortedLeft, sortedRight);
    }
};
