class Solution {
public:
    struct Node {
        Node * links[26];
        bool flag = false;
        bool isContains(char ch){      
            return links[ch-'a'] != NULL;
        }
        void put (char ch, Node * node){
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
    };
    class Trie {
    private : Node * root;
    public:
        Trie() {
            root = new Node();
        }
        
        void insert(string word) {
            Node * node = root;
            int n = word.size();
            for(int i = 0;i<n;i++){
                if(!(node ->isContains(word[i]))){      
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);          
            }
            node->flag = true;                      
        }
        
        string Transform(string sentence) {
            string word , ans = "";
            stringstream sobj;
            sobj<<sentence;
            while(!sobj.eof()){ 
                getline(sobj,word,' ');     
                string rootWord = "";
                Node * node = root;
                int n = word.size();
                int f = 0;
                for(int i = 0;i<n;i++){
                    if(node->isContains(word[i])){
                        rootWord.push_back(word[i]);          
                        node = node->get(word[i]);
                        if(node->flag){   
                            if(ans.size()>0) ans.push_back(' ');
                            ans += rootWord;
                            f= 1;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
                if(!f){         
                    if(ans.size()>0) ans.push_back(' ');
                    ans += word;
                }
                
            }
            return ans;
        }

    };
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto  word : dictionary) trie.insert(word);
        string ans = trie.Transform(sentence);
        return ans;
    }
};