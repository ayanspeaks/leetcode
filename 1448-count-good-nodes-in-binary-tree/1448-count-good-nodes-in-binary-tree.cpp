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
    int count = 0;  // Global variable to keep track of the number of good nodes
    
    // Helper function to perform DFS
    void dfs(TreeNode* node, int curMax) {
        if (!node) return;  // Base case: if the node is null, return
        
        // If the current node's value is greater than or equal to the current maximum, it is a good node
        if (node->val >= curMax) {
            count++;  // Increment the count of good nodes
            curMax = node->val;  // Update the current maximum value
        }
        
        // Recursively call dfs on the left and right children with the updated current maximum value
        dfs(node->left, curMax);
        dfs(node->right, curMax);
    }
    
    // Main function to count the number of good nodes
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);  // Start the DFS traversal from the root node
        return count;  // Return the count of good nodes
    }
};
