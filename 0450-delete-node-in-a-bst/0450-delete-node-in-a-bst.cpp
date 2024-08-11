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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: if the root is null, return null (nothing to delete)
        if (!root) return nullptr;  

        // Recursively search for the node to delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key);  // If the key is less, go left
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // If the key is greater, go right
        } else {
            // Node with the key found
            if (!root->left && !root->right) {
                return nullptr;  // Node has no children (leaf node)
            }
            if (!root->left || !root->right) {
                // Node has one child
                return root->left ? root->left : root->right; // Return the non-null child
            }
            
            // Node has two children: find the inorder predecessor (max of the left subtree)
            TreeNode* temp = root->left;
            while (temp->right) {
                temp = temp->right;  // Go to the rightmost node in the left subtree
            }
            root->val = temp->val;  // Replace the value of the current node with the inorder predecessor's value
            root->left = deleteNode(root->left, temp->val);  // Delete the inorder predecessor
        }
        
        return root;  // Return the (possibly new) root of the subtree
    }
};
