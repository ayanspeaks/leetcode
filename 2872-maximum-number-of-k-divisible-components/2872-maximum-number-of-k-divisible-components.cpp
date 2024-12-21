class Solution {
public:
void hope(int node,int p,vector<long long>&dp,vector<int>edge[],int &ans,vector<int>& values,int &k){
    dp[node]=(long long)values[node];
    long long div=(long long)k;
    for(int i=0;i<edge[node].size();i++){
        if(edge[node][i]!=p){
            hope(edge[node][i],node,dp,edge,ans,values,k);
            dp[node]=(long long)dp[node]+(long long)dp[edge[node][i]];
        }
    }
    if((dp[node]%k)==0){
        dp[node]=0;
        ans=ans+1;
    }
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>edge[n];
        for(int i=0;i<edges.size();i++){
            int n1=edges[i][0];
            int n2=edges[i][1];
            edge[n1].push_back(n2);
            edge[n2].push_back(n1);
        }
        int ans=0;
        vector<long long>dp(n,0);
        hope(0,-1,dp,edge,ans,values,k);    
        return ans;
    }
};