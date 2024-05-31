/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void keepConnecting(Node *lft, Node *rgt) {  
        if (!lft) return;
        lft->next = rgt;
        keepConnecting(lft->left, lft->right);
        keepConnecting(lft->right, rgt->left);
        keepConnecting(rgt->left, rgt->right); 
    }
public:
    Node* connect(Node* root) {
        if (root) keepConnecting(root->left, root->right);
        return root;
    }
};