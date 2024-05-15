class Solution {
public:
    bool ans = 0;
    void dfs(int i, int j, int& n, int& m, int& ind, vector<vector<int>>& vis, vector<vector<char>>& board, string& word){
        if(word[ind]==board[i][j]){
            vis[i][j]=1;
            ind++;
            if(ind==word.length()) ans=1;
        }

        if(j+1<m && word[ind]==board[i][j+1] && !vis[i][j+1]){
              dfs(i,j+1,n,m,ind,vis,board,word);
        }
        if(j-1>=0 && word[ind]==board[i][j-1] && !vis[i][j-1]){
              dfs(i,j-1,n,m,ind,vis,board,word);
        }
        if(i+1<n && word[ind]==board[i+1][j] && !vis[i+1][j]){
              dfs(i+1,j,n,m,ind,vis,board,word);
        }
        if(i-1>=0 && word[ind]==board[i-1][j] && !vis[i-1][j]){
              dfs(i-1,j,n,m,ind,vis,board,word);
        }
        if(!ans){vis[i][j]=0;ind--;}
    }

    bool exist(vector<vector<char>>& board, string word) {
       int n = board.size(), m = board[0].size(), ind = 0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
               vector<vector<int>> vis(n,vector<int>(m,0));
               dfs(i,j,n,m,ind,vis,board,word);
               if(ans) return 1;
               ind=0;
            }
        }
       }
       return ans;
    }
};