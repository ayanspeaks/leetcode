/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi = 0;
    void solve(TreeNode* root, int prev, int ans){
        if(root == 0) return;
        ans += 1;
        maxi = max(maxi,ans);
        if(prev == 1 || prev == 0) solve(root->right,1,0);
        else solve(root->right,1,ans);
        if(prev == -1 || prev  == 0) solve(root->left,-1,0);
        else solve(root->left,-1,ans);
    }
    int longestZigZag(TreeNode* root) {
        solve(root,0,-1);
        return maxi;
    }
};