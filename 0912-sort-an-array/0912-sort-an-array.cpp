class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        split(nums,temp,0,nums.size());
        return nums;
    }
    private:
    void split(vector<int> &nums,vector<int> &temp,int low,int high){
        if(high-low<2) return;
        int m=(high+low)/2;
        split(nums,temp,low,m),split(nums,temp,m,high);
        
        if(nums[m]>nums[m-1]) return;
        int l=low,r=m;
        for(int i=low;i<high;++i){
            if(r==high ||(l<m && nums[l]<=nums[r])) temp[i]=nums[l++];
            else temp[i]=nums[r++];
        }
        copy(begin(temp)+low,begin(temp)+high,begin(nums)+low);


    }
};