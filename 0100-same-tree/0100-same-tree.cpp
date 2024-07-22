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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both nodes are null
        if (p == nullptr && q == nullptr)
            return true;
        
        // Base case: one of the nodes is null
        if (p == nullptr || q == nullptr)
            return false;
        
        // Check if the current nodes' values are equal and recursively check their subtrees
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
        // If the values are not equal, the trees are not identical
        return false;
    }
};
