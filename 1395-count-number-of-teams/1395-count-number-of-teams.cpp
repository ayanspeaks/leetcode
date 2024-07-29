class Solution {
public:
     int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        for(int u=1;u<n;u++){
            int leftLess=0,leftGreater=0,rightLess=0,rightGreater=0;
            for(int j=0;j<u;j++){
                if(rating[j]>rating[u])leftGreater++;
                else leftLess++;
            }
            for(int j=u+1;j<n;j++){
                if(rating[j]>rating[u])rightGreater++;
                else rightLess++;
            }
            teams += (leftLess*rightGreater) + (leftGreater*rightLess);
        }
        return teams;
    }
};