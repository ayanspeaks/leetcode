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
    int maxi = 0;  // Global variable to store the maximum length of the zigzag path

    void solve(TreeNode* root, int direction, int length) {
        if (!root) return;  // Base case: if the node is null, return
        
        maxi = max(maxi, length);  // Update the maximum length if the current path is longer
        
        // If the previous move was to the right, move left and increment the length
        if (direction == 1) {
            solve(root->left, -1, length + 1);
            solve(root->right, 1, 1);  // Reset the length for a right move
        }
        // If the previous move was to the left, move right and increment the length
        else {
            solve(root->right, 1, length + 1);
            solve(root->left, -1, 1);  // Reset the length for a left move
        }
    }

    int longestZigZag(TreeNode* root) {
        if (root) {
            solve(root->left, -1, 1);  // Start DFS by moving left from the root
            solve(root->right, 1, 1);  // Start DFS by moving right from the root
        }
        return maxi;  // Return the maximum length of the zigzag path
    }
};
