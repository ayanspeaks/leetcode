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
    int inorder(TreeNode* root, int& k) {
        if (!root) return -1;
        
        // Traverse the left subtree
        int left = inorder(root->left, k);
        if (k == 0) return left;  // If k is 0 after left traversal, return the left result
        
        // Process the current node
        if (--k == 0) return root->val;  // Decrease k and check if this is the k-th element
        
        // Traverse the right subtree
        return inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
