class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> z;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                z.push_back(i);//storing index of all the zeros
        }
        int maxi=INT_MIN,n1=z.size();
        if(n1<=1)
            return n-1;//since we have to delete one element
        if(n1>=2)
        {
             maxi=max(maxi,z[1]-1);//if 1st zero is deleted
             maxi=max(maxi,n-z[n1-2]-2);//tracking if last zero is deleted
        }
        for(int i=1;i<n1-1;i++)
        {
            maxi=max(maxi,z[i+1]-z[i-1]-2);//if any zero in between is deleted
        }
        return maxi;
    }
};