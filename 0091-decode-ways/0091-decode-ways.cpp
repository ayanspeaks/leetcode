class Solution {
public:
int n;
int dp[105];
map<int,char>mp;
int f(int ind,string &s)
{
     if(s[ind]=='0')return 0;

     if(ind>=n-1)return 1;
if(dp[ind]!=-1)return dp[ind];
int c=0;
string k="";
    for(int i=ind;i<n;i++){
k+=s[i];
if(k.size()>2)break;
if(mp.find(stoi(k))!=mp.end()){
    c+=f(i+1,s);
}}

return dp[ind]=c;

}
    int numDecodings(string s) {
      n=s.size();  
      for(int i=0;i<26;i++){
          mp[i+1]=(i+'A');
      }
      memset(dp,-1,sizeof(dp));
      return f(0,s);
    }
};
