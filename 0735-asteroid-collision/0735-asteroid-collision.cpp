class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int s=0;
        while(s<asteroids.size()){
            int aster=asteroids[s];
            if(ans.size()==0){
                ans.push_back(aster);
                s++;
                continue;
            }
            int topi=ans.back();
            if((aster>0 && topi>0) || (aster<0 && topi<0))ans.push_back(aster),s++;
            else{
                if(aster<0){
                    if(abs(aster)==topi)ans.pop_back(),s++;
                    else if(abs(aster)>topi)ans.pop_back();
                    else s++;
                }
                else ans.push_back(aster),s++;
            }
        }

        return ans;
    }
};