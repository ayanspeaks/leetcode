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
    void reorderList(ListNode* head) {
        int d=0;
        ListNode*ptr=head,*p=head,*pt=NULL;
        while(ptr)
        {
            d++;
            ptr=ptr->next;
        }
        if(d<=2)
        {
            return ;
        }
        d=d/2;
        ptr=head;
        while(ptr)
        {
            if(d==0)
            {
                break;
            }
             d--;
            p=ptr;
            ptr=ptr->next;
        }
        p->next=NULL;
        while(ptr)
        {
            p=ptr;
            ptr=ptr->next;
            p->next=pt;
            pt=p;
        }
        p=pt;
        while(head)
        {
            ptr=head->next;
            p=pt->next;
            head->next=pt;
            if(ptr)
            pt->next=ptr;
            head=ptr;
            pt=p;
        }
    }
};