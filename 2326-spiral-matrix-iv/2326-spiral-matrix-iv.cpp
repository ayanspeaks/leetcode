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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m , vector<int> (n,-1));

        int t = 0, d = m-1, l = 0 , r = n-1;

        while(head != NULL && t <= d && l <= r){
            // cout << t << " " << d << " " << l << " " << r << endl;
            for(int i=l;i<=r && head != NULL;i++){
                ans[t][i] = head -> val;
                // cout << ans[t][i] << endl;
                head = head -> next;
            }
            
            t++;
            for(int i=t;i<=d && head != NULL;i++){
                ans[i][r] = head -> val;
                // cout <<  ans[i][r] << endl;

                head = head -> next;
            }
            r--;
            for(int i=r;i>=l && head != NULL;i--){
                ans[d][i] = head -> val;
                // cout <<   ans[d][i] << endl;

                head = head -> next;
            }
            d--;
            for(int i=d;i>=t && head != NULL;i--){
                ans[i][l] = head -> val;
                // cout <<  ans[i][l] << endl;
                head = head -> next;
            }
            l++;
            // cout << head -> val << endl;
        }

        return ans;
    }
};
