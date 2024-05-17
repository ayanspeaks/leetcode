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
    ListNode* partition(ListNode* head, int x) {
        vector<int>v1;
        vector<int>v2;
        ListNode* temp = head;
        while(temp != nullptr){
            if(temp->val < x){
                v1.push_back(temp->val);
                temp = temp->next;
            }
            else{
                v2.push_back(temp->val);
                temp= temp->next;
            }         
        }
        temp = head;
        while(temp != nullptr){
            for(auto it:v1){
                temp->val = it;
                temp=temp->next;
            }
            for(auto it:v2){
                temp->val = it;
                temp=temp->next;
            }
        }
        return head;
    }
};