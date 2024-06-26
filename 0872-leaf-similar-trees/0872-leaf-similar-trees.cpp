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
    void preorder(TreeNode* root, vector<int> &ls) {
        if(root) {
            if(root->left == NULL && root->right == NULL) ls.push_back(root->val);
            preorder(root->left, ls);
            preorder(root->right, ls);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ls1, ls2;
        preorder(root1, ls1);
        preorder(root2, ls2);
        return ls1 == ls2;
    }
};