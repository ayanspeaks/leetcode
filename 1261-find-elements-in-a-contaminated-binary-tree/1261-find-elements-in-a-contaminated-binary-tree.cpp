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
class FindElements {
public:
    map<int,bool>check;
    void make(TreeNode*root,int x){
        check[x]=true;
        if(root->left){
            int value=x*2+1;
            make(root->left,value);
        }
        if(root->right){
            int value=x*2+2;
            make(root->right,value);
        }
        
    }
    FindElements(TreeNode* root) {
      make(root,0);
    }
    
    bool find(int target) {
        return check[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */