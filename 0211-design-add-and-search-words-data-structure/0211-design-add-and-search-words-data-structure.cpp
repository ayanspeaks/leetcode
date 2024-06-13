class TrieNode{
public:
    map<char, TrieNode*> child;
    bool endOfWord;
    TrieNode(){
        endOfWord=false;
    }
}; 

class WordDictionary {
public:
    TrieNode*root;
    WordDictionary() {
        this->root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode*node=root;
        for(auto c:word){
            if(node->child.count(c)==0) {
                node->child[c]= new TrieNode();
            }
            node=node->child[c];
        }
        node->endOfWord=true;
    }
    
    bool searchInNode(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (!node->child.count(ch)) {
                // if the current character is '.'
                // check all possible nodes at this level
                if (ch == '.') {
                    for (auto x : node->child) {
                        TrieNode* child = x.second;
                        if (searchInNode(word.substr(i + 1), child)) {
                            return true;
                        }
                    }
                }
                // if no nodes lead to answer
                // or the current character != '.'
                return false;
            } else {
                // if the character is found
                // go down to the next level in trie
                node = node->child[ch];
            }
        }
        return node->endOfWord;
    }

    bool search(string word) {
        return searchInNode(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */