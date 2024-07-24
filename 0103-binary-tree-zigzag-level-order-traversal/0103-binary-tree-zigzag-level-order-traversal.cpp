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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result; // If the root is null, return an empty vector

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // Flag to control the zigzag pattern

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Place node value in the appropriate position based on zigzag pattern
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = node->val;

                // Enqueue child nodes for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Toggle the direction for the next level
            leftToRight = !leftToRight;

            // Add the current level to the result
            result.push_back(level);
        }

        return result;
    }
};
