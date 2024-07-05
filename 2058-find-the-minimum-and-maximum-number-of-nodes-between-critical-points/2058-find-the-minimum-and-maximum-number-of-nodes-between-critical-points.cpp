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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
          vector<int> ans(2,-1);
        if(head==NULL || head->next==NULL || head->next->next==NULL || head->next->next->next==NULL){
            return ans;
        }
        ListNode* prev=head;
        ListNode* nex=head->next->next;
        ListNode* cur=head->next;
        int index=1;
        vector<int> points;
        while(nex){
            if(cur->val<prev->val && cur->val<nex->val){
                 points.push_back(index);
            }
            if(cur->val>prev->val && cur->val>nex->val){
                 points.push_back(index);
            }
            index++;
            prev=prev->next;
            cur=cur->next;
            nex=nex->next;

        }
        int minn= INT_MAX;
        int maxx=INT_MIN;
        if(points.size()<2){
            return ans;
        }
            sort(points.begin(),points.end());
            for(int i=0;i<points.size()-1;i++){
                minn=min(minn,abs(points[i]-points[i+1]));
            }
            maxx=abs(points[0]-points[points.size()-1]);
            ans[0]=minn;
            ans[1]=maxx;
      return ans;
    }
};