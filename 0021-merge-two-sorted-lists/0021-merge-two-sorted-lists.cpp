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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If list1 is null, return list2 (base case)
        if (list1 == NULL)
            return list2;
        
        // If list2 is null, return list1 (base case)
        if (list2 == NULL)
            return list1;

        // Compare the values of the current nodes of both lists
        if (list1->val <= list2->val) {
            // If list1's value is smaller or equal, link list1's next to the result of merging the rest of list1 and list2
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            // If list2's value is smaller, link list2's next to the result of merging list1 and the rest of list2
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
