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
    TreeNode* prev = nullptr;  // Pointer to track the previous node in in-order traversal

    bool isValidBST(TreeNode* root) {
        // Base case: an empty tree is a valid BST
        if (!root) return true;

        // Recursively check the left subtree
        if (!isValidBST(root->left)) return false;

        // Check the current node against the previous node
        if (prev && root->val <= prev->val) {
            return false;  // Not a valid BST
        }

        // Update prev to the current node
        prev = root;

        // Recursively check the right subtree
        return isValidBST(root->right);
    }
};
