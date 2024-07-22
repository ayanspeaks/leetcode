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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the tree is empty, there is no path
        if (root == nullptr) {
            return false;
        }

        // Check if the current node is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            // If it's a leaf, check if the path sum equals the target sum
            return root->val == targetSum;
        }

        // Recursively check the left and right subtrees with the updated target sum
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};
