class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int st=0,n=arr.size(),en=n-1;
        for(;st<n-1;st++){
            if(arr[st]>arr[st+1])break;
        }
        if(st==n-1)return 0;
        for(;en>st;en--){
            if(arr[en-1]>arr[en])break;
        }
        int i=0, ans=min(en,n-st-1);
        while(i<=st && en<n){
            if(arr[i]<=arr[en]){ans=min(ans,en-i-1);i++;}
            else en++;
        }
        return ans;
    }
};