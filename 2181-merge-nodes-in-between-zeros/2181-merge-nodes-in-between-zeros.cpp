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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* list = res;
        int b=0;
        head = head->next;
        while(head) {
            b = b + head->val;
            if(head->val == 0) {
                ListNode* temp = new ListNode(b);
                list->next = temp;
                list = list->next;
                b=0;
            }
            head = head->next;
        }
        return res->next;
    }
};