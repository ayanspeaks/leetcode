class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 0, high = *max_element(quantities.begin(),quantities.end());
        int minSize = 0;
        while(low <= high){
            int mid = (high + low) / 2;
            int j = 0;
            auto copyVec = quantities;
            for(int i = 1; i <= n && j < quantities.size(); ++i){
                if(copyVec[j] > mid){
                    copyVec[j] -= mid;
                } else{
                    j++;
                }
            }
            if(j == quantities.size()){
                minSize = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return minSize;
    }
};