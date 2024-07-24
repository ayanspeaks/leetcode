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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // Final vector to store level order traversal
        if (root == nullptr) return result; // If root is null, return an empty vector

        queue<TreeNode*> q; // Queue to facilitate level order traversal
        q.push(root); // Start with the root node

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> currentLevel; // Vector to store node values at the current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); // Get the node at the front of the queue
                q.pop(); // Remove the node from the queue
                currentLevel.push_back(node->val); // Add the node's value to the current level vector

                if (node->left) q.push(node->left); // If left child exists, add it to the queue
                if (node->right) q.push(node->right); // If right child exists, add it to the queue
            }

            result.push_back(currentLevel); // Add the current level vector to the final result
        }

        return result; // Return the final level order traversal
    }
};
