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
public:
    Node* connect(Node* root) {
        Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
        while (root) {
            for (auto i: {root->left, root->right}) 
                if(i){
                    cur->next = i;
                    cur = cur->next;
                }
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        return head;
    }
};