class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> valtoind;
        for(int i=0;i<n;i++)
        {
            valtoind[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto e:valtoind)
        {
            vector<int> temp=e.second;
            int maxi=0;
            int s=temp.size();
            if(s==1) maxi=n/2;
            
            for(int i=0;i<s;i++)
            {
                maxi=max(maxi,(abs(temp[(i+1)%s]-temp[i]+n)%n)/2);
            }
            ans=min(ans,maxi);
        }
        return ans;
    }
};