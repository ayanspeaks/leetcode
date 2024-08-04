class Solution {
public:
    const int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int>v(n*(n+1)/2+1,0);
        int index=1;
        for (int i=0;i<n;++i) {
            int currentsum=0;
            for (int j=i;j<n;++j) {
                currentsum+=nums[j];
                v[index++]=(currentsum);
            }
        }
        sort(v.begin(),v.end());
        int sum=0;
        for(int i=l;i<=r;++i){
            sum=(sum+v[i])%mod;
        }
        return sum%mod;
    }
};