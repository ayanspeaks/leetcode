class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int total = 0;
        for(int i = 0; i < f.size() && total < n; i++){
            if(f[i] == 0) {
                int next = (i == f.size()-1) ? 0 : f[i + 1]; 
                int prev = (i == 0) ? 0 : f[i - 1];
            if(prev == 0 && next == 0){
                f[i] = 1;
                total ++;
            }
        }
    }
         return total == n;
    }
};