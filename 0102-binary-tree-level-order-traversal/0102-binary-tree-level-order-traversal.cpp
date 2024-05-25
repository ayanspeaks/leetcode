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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalvector;
         if(root==NULL)
        {
            return finalvector;
        }
        vector<int> levelvector1val;
        vector<TreeNode*> levelvector1poi;
        levelvector1val.push_back(root->val);
        levelvector1poi.push_back(root);
        while(levelvector1poi.size()>0)
        {
            finalvector.push_back(levelvector1val);
            vector<int> levelvector2val;
            vector<TreeNode*> levelvector2poi;
            for(int i=0;i<levelvector1poi.size();i++)
            {
                if(levelvector1poi[i]->left!=NULL)
                {
                    levelvector2val.push_back(levelvector1poi[i]->left->val);
                    levelvector2poi.push_back(levelvector1poi[i]->left);
                }
                if(levelvector1poi[i]->right!=NULL)
                {
                    levelvector2val.push_back(levelvector1poi[i]->right->val);
                    levelvector2poi.push_back(levelvector1poi[i]->right);
                }
            }
            levelvector1val=levelvector2val;
            levelvector1poi=levelvector2poi;
        }
        return finalvector;
    }
};
