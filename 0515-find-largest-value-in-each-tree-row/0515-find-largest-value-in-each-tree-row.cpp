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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty())
        {
            int max = INT_MIN;
            for(int level=q.size();level>0;level--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->val > max)
                    max = node->val;
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};