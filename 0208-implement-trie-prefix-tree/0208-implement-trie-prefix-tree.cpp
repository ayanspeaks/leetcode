class TrieNode {
public:
    TrieNode* links[26];
    bool isLeaf = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char c : word) {
            if(!temp -> links[c - 'a']) {
                temp -> links[c - 'a'] = new TrieNode();
            }
            temp = temp -> links[c - 'a'];
        }
        temp -> isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(char c : word) {
            if(!temp -> links[c - 'a']) return false;
            temp = temp -> links[c - 'a'];
        }
        return temp -> isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char c : prefix) {
            if(!temp -> links[c - 'a']) return false;
            temp = temp -> links[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */