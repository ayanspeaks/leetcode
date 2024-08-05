/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Create a map to store the original nodes and their corresponding copies
        map<Node*, Node*> m;

        // First pass: create a copy of each node and store it in the map
        Node* temp = head;
        while (temp != NULL) {
            // Create a new node with the same value as the original node
            Node* copy = new Node(temp->val);
            // Map the original node to its copy
            m[temp] = copy;
            // Move to the next node in the original list
            temp = temp->next;
        }
        // Second pass: assign the next and random pointers for the copied nodes
        temp = head;
        while (temp != NULL) {
            // Set the next pointer of the copied node
            m[temp]->next = m[temp->next];
            // Set the random pointer of the copied node
            m[temp]->random = m[temp->random];
            // Move to the next node in the original list
            temp = temp->next;
        }
        // Return the head of the copied list, which corresponds to the copied version of the original head
        return m[head];
    }
};
