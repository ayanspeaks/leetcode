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
        if (!head || !head->next) {
            return head;
        }

        auto merge = [](ListNode* left, ListNode* right) -> ListNode* {
            ListNode dummy(0);
            ListNode* curr = &dummy;

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

            curr->next = left ? left : right;

            return dummy.next;
        };

        auto findMiddle = [](ListNode* node) -> ListNode* {
            ListNode* slow = node;
            ListNode* fast = node->next;

            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        };

        ListNode* mid = findMiddle(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        ListNode* sortedLeft = sortList(head);
        ListNode* sortedRight = sortList(rightHead);

        return merge(sortedLeft, sortedRight);
    }
};
