/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or root is one of p or q, return root
        if (!root || root == p || root == q) return root;

        // Search for LCA in the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // Search for LCA in the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, root is the LCA
        if (left && right) return root;
        // If left is null, it means both p and q are in the right subtree
        if (!left) return right;
        // If right is null, it means both p and q are in the left subtree
        return left;
    }
};
