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
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete_vector) {
        bitset<1024> to_delete;
        for (int v : to_delete_vector) to_delete[v] = true;

        vector<TreeNode*> ans;
        if (delNodes(root, to_delete, ans)) {
            // |root| node did survive, add it the to answer.
            ans.push_back(root);
        }
        return ans;
    }
    
    TreeNode* delNodes(TreeNode* node, const bitset<1024>& to_delete, vector<TreeNode*>& ans) {
        if (!node) return nullptr;
        
        // Visit children first (post order).
        node->left = delNodes(node->left, to_delete, ans);
        node->right = delNodes(node->right, to_delete, ans);
        
        // We need to keep this node.
        if (!to_delete[node->val]) return node;

        // Delete this node. If it has children add them to the answer.
        if (node->left) ans.push_back(node->left);
        if (node->right) ans.push_back(node->right);

        delete node;
        return nullptr;
    }
};