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
    //inorder travesal
    void inorder( TreeNode* root,vector<int> &nod){
        if(!root) return;
        inorder(root->left,nod);
        nod.push_back(root->val);
        inorder(root->right,nod);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nod;
        inorder(root,nod);
        return nod[k-1];
    }
};