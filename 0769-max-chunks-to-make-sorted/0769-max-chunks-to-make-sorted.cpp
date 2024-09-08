class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int ans=0,n=arr.size(),mx=-1;
        for(int i=0;i<n;i++) {
            mx=max(mx,arr[i]);
            if(mx==i) ans++;
        }
        return ans;
    }
};