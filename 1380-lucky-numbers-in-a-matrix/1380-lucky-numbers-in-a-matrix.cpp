class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        unordered_map<int,int> mp;

        for(int i=0;i<m;i++){
           int mini=1e9;
            for(int j=0;j<n;j++){
               mini=min(matrix[i][j],mini);  
            }
            mp[i]=mini;
        }

        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int maxi=-1e9;
            int max_ind;
            for(int j=0;j<m;j++){
                if(matrix[j][i]>maxi){
                    maxi=matrix[j][i];
                    max_ind=j;
                } 
            }
            if(mp[max_ind]==maxi) ans.push_back(maxi);
        }
        return ans;
    }
};
