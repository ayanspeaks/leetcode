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
    int solve(TreeNode* root) {
        // Base case: if the node is null, return 0
        if (root == nullptr) return 0;
        
        // Recursively count the nodes in the left and right subtrees and add 1 for the current node
        return 1 + solve(root->left) + solve(root->right);
    }

    int countNodes(TreeNode* root) {
        // Use the helper function to count the nodes in the tree
        return solve(root);
    }
};