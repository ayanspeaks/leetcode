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
class Solution
{
public:
	void solve(TreeNode *root, int &x)
	{
		if (root == NULL)
			return;
		solve(root->right, x);
		if (root->val >= 0)
			root->val += x;
		root->val = -root->val;
		x = abs(root->val);
		if (root->left)
		{
			solve(root->left, x);
			if (root->val > 0)
				x += root->val;
		}
	}
	void solve1(TreeNode *root)
	{
		if (!root)
			return;
		root->val = -root->val;
		solve1(root->left);
		solve1(root->right);
	}
	TreeNode *bstToGst(TreeNode *root)
	{
		int x = 0;
		solve(root, x);
		solve1(root);
		return root;
	}
};