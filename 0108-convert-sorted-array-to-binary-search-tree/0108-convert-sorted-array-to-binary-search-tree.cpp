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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the helper function to convert the entire range of the array into a BST
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    // Helper function to convert a subrange of the array into a BST
    TreeNode* sortedArrayToBST(vector<int>& nums, int beg, int end) {
        // Base condition: if the starting index is greater than the ending index, return NULL
        if (beg > end)
            return NULL;

        // Find the middle element of the current subrange
        int mid = (beg + end) / 2;

        // Create a new tree node with the middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively construct the left subtree using the left subrange
        root->left = sortedArrayToBST(nums, beg, mid - 1);

        // Recursively construct the right subtree using the right subrange
        root->right = sortedArrayToBST(nums, mid + 1, end);

        // Return the constructed tree node (root of this subrange)
        return root;
    }
};
