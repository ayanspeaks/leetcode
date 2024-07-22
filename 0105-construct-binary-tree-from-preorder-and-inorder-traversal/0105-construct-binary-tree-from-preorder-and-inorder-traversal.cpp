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
    int preInd = 0;  // Index for current root in preorder traversal
    unordered_map<int, int> inMap;  // HashMap to store inorder value -> index mapping

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build the hashmap to quickly find the root position in inorder array
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        // Call the recursive function to construct the tree
        return createTree(preorder, 0, inorder.size() - 1);
    }

    TreeNode* createTree(vector<int>& preorder, int start, int end) {
        // Base case: if the current subtree is empty
        if (start > end) {
            return nullptr;
        }

        // The current root value is the current element in preorder
        TreeNode* node = new TreeNode(preorder[preInd++]);

        // Find the index of this root in inorder array
        int pos = inMap[node->val];

        // Recursively build the left and right subtrees
        node->left = createTree(preorder, start, pos - 1);
        node->right = createTree(preorder, pos + 1, end);

        return node;
    }
};
