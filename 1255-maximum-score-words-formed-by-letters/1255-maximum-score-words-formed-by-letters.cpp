class Solution {
public:
    void solve(int i,int &n,vector<int> &v,vector<int> &score,int &ans,int sum,vector<string> &words){
        ans = max(ans,sum);
        if(i>=n)return;
        vector<int> tmp = v;
        int j=0,sum1=0;
        for(j = 0; j < words[i].length(); j++){
            tmp[words[i][j]-'a']--;
            sum1 += score[words[i][j]-'a'];
            if(tmp[words[i][j]-'a']<0)break;
        }
        if(j==words[i].length()){
            solve(i+1,n,tmp,score,ans,sum+sum1,words);
        }
        solve(i+1,n,v,score,ans,sum,words);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> v(26,0);
        for(auto &i: letters){
            v[i-'a']++;
        }
        int ans = 0,n=words.size();
        solve(0,n,v,score,ans,0,words);
        return ans;
    }
};