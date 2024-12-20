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
    TreeNode* reverseOddLevels(TreeNode* root) {
    int level = 0;
    vector<TreeNode*> q{root};    
    while (!q.empty() && q[0]->left != nullptr) {
        vector<TreeNode*> q1;
        for (auto n : q)
            q1.insert(end(q1), {n->left, n->right});
        if (--level % 2)
            for (int i = 0, j = q1.size() - 1; i < j; ++i, --j)
                swap(q1[i]->val, q1[j]->val);
        swap(q, q1);
    }
    return root;
}
};