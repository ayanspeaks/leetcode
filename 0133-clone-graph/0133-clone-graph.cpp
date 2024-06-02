/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldtonew;
        return dfs(node, oldtonew);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldtonew) {
        if (!node) {
            return nullptr;
        }
        if (oldtonew.count(node)) {
            return oldtonew[node];
        }
        Node* copy = new Node(node->val);
        oldtonew[node] = copy;
        for (Node* n : node->neighbors) {
            copy->neighbors.push_back(dfs(n, oldtonew));
        }
        return copy;
        
    }
};