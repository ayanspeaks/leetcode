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

    int findLen(ListNode*head){
        int cnt=0;
        while(head){
            head=head->next;
            ++cnt;
        }
        return cnt;
    }

    ListNode* divide(int each,ListNode*&temp){
        if(each==0 || temp==NULL) return NULL;
         ListNode* head = temp;
        for (int i = 0; i < each - 1; ++i) {
           temp = temp->next;
        }

        if (temp) {
            ListNode* nxtNode = temp->next;
            temp->next = nullptr;
            temp = nxtNode;
        }

        return head;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        ListNode*temp=head;
        int len=findLen(head);
        int each=len/k;
        int extra=len%k;

        ListNode*guest=NULL;
        for(int i=0;i<k;i++){

            if(i<extra) guest= divide(each+1,temp);
            else guest= divide(each,temp);

            result.push_back(guest);
        }

        return result;
    }
};