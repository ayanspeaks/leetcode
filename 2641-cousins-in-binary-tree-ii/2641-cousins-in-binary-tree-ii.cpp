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

	void levelorder(TreeNode* root,vector<int> &sum)
	{
		queue<TreeNode*> q;
		q.push(root);

		while(!q.empty())
		{
			int levelSum=0;
			int size=q.size();

			for(int i=0;i<size;i++)
			{
				auto node = q.front();
				q.pop();

				levelSum += node->val;

				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}            
			sum.push_back(levelSum);
		}
	}

	void preorder(TreeNode* root,int level,vector<int> &sum)
	{
		if(!root)
			return;

		int leftVal=-1,rightVal=-1;

		if(level!=0 && root->left)
			leftVal = root->left->val;

		if(level!=0 && root->right)
			rightVal = root->right->val;    

		if(level+1<sum.size())
		{
			int val = sum[level+1];
			if(leftVal!=-1)
				val -= leftVal;
			if(rightVal!=-1)
				val -= rightVal;

			if(root->left)
				root->left->val = val;

			if(root->right)
				root->right->val = val;
		}

		preorder(root->left,level+1,sum);
		preorder(root->right,level+1,sum);
	}

	TreeNode* replaceValueInTree(TreeNode* root) {

		vector<int> sum;

		levelorder(root,sum);
		preorder(root,0,sum);

		root->val = 0;                     
		if(root->left)
			root->left->val=0;

		if(root->right)
			root->right->val=0;

		return root;
	}
 
 };