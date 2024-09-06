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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> numSet(nums.begin(), nums.end());

        while (head && numSet.count(head->val)) {
            head = head->next;
        }

        ListNode* current = head;
        ListNode* nextNode = head ? head->next : nullptr;

        while (current) {
            
            while (nextNode && numSet.count(nextNode->val)) {
                nextNode = nextNode->next;
            }
         
            current->next = nextNode;
            current = nextNode;
            if (nextNode) {
                nextNode = nextNode->next;
            }
        }

        return head;
    }
};