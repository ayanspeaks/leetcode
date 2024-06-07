class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int ans=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        string num=to_string(maxi);
        int len=num.size();
        long int a=10;
        long int b=1;
        vector<int>count(10,0);
        vector<int>dup(n);
        for(int i=0;i<len;i++){
            for(auto j:nums){   
                int val=((j%a)/b);
                count[val]++;
            }
            for(int j=1;j<10;j++){
                count[j]+=count[j-1];
            }
            for(int k=n-1;k>=0;k--){
                int j=nums[k];
                int val=((j%a)/b);
                count[val]--;
                int ind=count[val];
                dup[ind]=j;
            }
            for(int j=0;j<n;j++){
                nums[j]=dup[j];
            }
            for(int j=0;j<10;j++){
                count[j]=0;
            }
            a*=10;
            b*=10;
        }
        for(int i=1;i<n;i++){
            ans=max(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};