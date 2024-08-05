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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int maxVal = 0;

        // Get the middle of the linked list
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse the second part of the linked list
        ListNode *nextNode, *prev = NULL;
        while (slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Calculate the maximum twin sum
        while (prev) {
            maxVal = max(maxVal, head->val + prev->val);
            prev = prev->next;
            head = head->next;
        }

        return maxVal;
    }
};
