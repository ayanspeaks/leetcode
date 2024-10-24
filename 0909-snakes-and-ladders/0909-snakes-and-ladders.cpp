class Solution {
private:
    int getBoardValue(int dest, vector<vector<int>>& board){
        int n = board.size();
        int row = n - ceil(dest * 1.0 / n);
        int col;
        if((n - row) & 1){
            if(dest % n == 0){
                col = n - 1;
            }else{
                col = dest % n - 1;
            }
        }
        else{
           if(dest % n == 0){
               col = 0;
           }else{
               col = n - dest % n ;
           }
        }
        return board[row][col];
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int src = 1;
        int move = 0;
        int marker = INT_MAX;
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        q.push(marker);
        while(!q.empty()){
            int src = q.front();
            q.pop();
            if(src == marker){
                if(!q.empty()){
                    q.push(marker);
                    move++;
                }
            }
            else{
                for(int result = 1 ; result <= 6 ; result++){
                    int dest = src + result;
                    if(visited[dest]) continue;
                    visited[dest] = true;
                    if(dest < n * n){
                        int boardValue = getBoardValue(dest, board);
                        if(boardValue != -1){
                            dest = boardValue;
                        }
                        q.push(dest);
                    }
                    if (dest == n * n) return move + 1;
                }
            }
        }
        return -1;
        
    }
};