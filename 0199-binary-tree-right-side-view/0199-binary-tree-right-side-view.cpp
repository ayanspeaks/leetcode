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
    void solve(TreeNode* root, int level, vector<int>& ans) {
        if (root == NULL) {
            return;  // Base case: if the node is null, return
        }
        // If the current level is equal to the size of ans, add the node's value to ans
        if (level == ans.size()) {  
            ans.push_back(root->val);
        }
        // Traverse the right subtree first
        solve(root->right, level + 1, ans);
        // Traverse the left subtree next
        solve(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;  // Vector to store the right side view
        solve(root, 0, ans);  // Initialize DFS from the root node with level 0
        return ans;  // Return the vector containing the right side view
    }
};
