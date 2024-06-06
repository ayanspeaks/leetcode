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
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
         while (headb != NULL)
        {
            // DENIZ BRAVEN
            ListNode *temp = heada;
            while(temp!=NULL)
            {
                if (temp == headb)
                return headb;
                temp = temp->next;
            }
            headb = headb->next;
        }
        return NULL;
    }
};