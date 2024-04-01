class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());
        int n=c.size(), i;
        for(i=1; i<=n; ++i){
            if(c[n-i]<i) break;
        }
        return i-1;
    }
};