class Solution {
    string b;
private:
    void dfs(string word, vector<string> &v, unordered_map<string,int> mp, vector<vector<string>> &ans){
        if(word==b) {reverse(v.begin(), v.end()); ans.push_back(v);reverse(v.begin(), v.end()); return;}
        int steps = mp[word];
        for(int i=0;i<word.length();i++){
            char a = word[i];
            for(char c='a';c<='z';c++){
                word[i] = c;
                if(mp.find(word)!=mp.end() && mp[word] ==steps -1){
                    v.push_back(word);
                    dfs(word, v, mp, ans);
                    v.pop_back();
                }
            }
            word[i] = a;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_map<string, int> m;
        m[beginWord]=1;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        int s = beginWord.size();
        while(!q.empty()){
            string word = q.front();
            int steps = m[word];
            q.pop();
            if(word==endWord) break;
            for(int i=0;i<s;i++){
                char a=word[i];
                for(char c='a';c<='z';c++){
                    word[i] = c;
                    if(st.count(word)>0){
                        q.push(word);
                        st.erase(word);
                        m[word]=steps+1;
                    }
                }
                word[i]=a;
            }
        }
        vector<vector<string>> ans;
        vector<string> v;
        v.insert(v.begin(),endWord);
        dfs(endWord, v, m, ans);
        return ans;
    }
};