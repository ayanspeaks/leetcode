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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;  // Start with the root node

        // Traverse the tree until we find the value or reach a null pointer
        while (temp != nullptr) {
            if (temp->val == val) {
                return temp;  // Value found, return the node
            }

            // Move left if the value is less than the current node's value
            if (temp->val > val) {
                temp = temp->left;
            } else {
                // Move right if the value is greater
                temp = temp->right;
            }
        }
        
        return nullptr;  // Value not found, return null
    }
};
