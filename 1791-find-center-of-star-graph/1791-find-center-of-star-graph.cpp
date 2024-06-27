class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mpp;
        for(int i =0 ;i<edges.size();i++){
            mpp[edges[i][0]]++;
            mpp[edges[i][1]]++;

        }
        int nodes = 0 ;
        for(auto it:mpp){
            nodes++;
        }
        for(auto it:mpp){
          if(it.second==nodes-1)return it.first;
        }
        return 1;
    }
};