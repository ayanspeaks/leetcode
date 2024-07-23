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
    unordered_map<long, int> map;  // Map to store the frequency of prefix sums
    int count = 0;  // Counter to keep track of the number of valid paths

    // Helper function to perform DFS and count valid paths
    void countPathSum(TreeNode* root, int target, long sum) {
        if (!root) return;  // Base case: if the node is null, return

        sum += root->val;  // Update the current path sum with the node's value
        
        // Check if the current path sum equals the target
        if (sum == target) count++;

        // Check if there exists a subpath that sums to the target
        if (map.find(sum - target) != map.end()) 
            count += map[sum - target];
        
        // Increment the count of the current path sum in the map
        map[sum]++;
        
        // Recursively call for left and right subtrees
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        
        // Decrement the count of the current path sum in the map (backtracking)
        map[sum]--;
    }

    // Main function to count the number of valid paths that sum to the target
    int pathSum(TreeNode* root, int targetSum) {
        countPathSum(root, targetSum, 0);  // Initialize DFS
        return count;  // Return the count of valid paths
    }
};
