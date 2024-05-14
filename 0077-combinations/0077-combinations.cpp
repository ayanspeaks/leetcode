class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(1,k,n,curr,ans);
        return ans;
    }
private:
    void solve(int i, int k, int n, vector<int>&curr,vector<vector<int>>& ans){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        else if(i>n) return;
        else{
            curr.push_back(i);
            solve(i+1, k, n, curr, ans);
            curr.pop_back();
            solve(i+1, k, n, curr, ans);
        }
    }

};