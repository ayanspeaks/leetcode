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
    bool c(TreeNode* left, TreeNode* right) {
        // Base case: if either node is null, they must both be null to be symmetric
        if (!left || !right) {
            return left == right;
        }
        // Check if the current nodes' values are equal
        if (left->val != right->val) return false;
        // Recursively check the left subtree of left with the right subtree of right
        // and the right subtree of left with the left subtree of right
        return c(left->left, right->right) && c(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        // A tree is symmetric if the left and right subtrees are mirror images
        return c(root, root);
    }
};
