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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int& idx, int start, int end, unordered_map<int, int>& inMap) {
        // Base case: if the current subtree is empty, return nullptr
        if (idx < 0 || start > end) return nullptr;

        // Get the current root value from postorder traversal
        int rootVal = postorder[idx--];
        // Create the root node
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the current root in the inorder traversal
        int inIndex = inMap[rootVal];

        // Recursively build the right subtree
        root->right = buildTreeHelper(inorder, postorder, idx, inIndex + 1, end, inMap);
        // Recursively build the left subtree
        root->left = buildTreeHelper(inorder, postorder, idx, start, inIndex - 1, inMap);

        // Return the root node
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a hashmap for quick index lookup in inorder traversal
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Start from the last element in the postorder array
        int idx = postorder.size() - 1;

        // Call the helper function to build the tree
        return buildTreeHelper(inorder, postorder, idx, 0, inorder.size() - 1, inMap);
    }
};
