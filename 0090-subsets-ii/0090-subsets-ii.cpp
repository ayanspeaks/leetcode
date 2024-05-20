class Solution {
public:
    // vector<vector<int>>ans;
    void f(set<vector<int>>& res,const vector<int>& nums,int pos,vector<int> temp){
		if(pos==nums.size()){
            sort(temp.begin(),temp.end());
			res.insert(temp);
			return;
		}
		f(res,nums,pos+1,temp);
		temp.push_back(nums[pos]);
		f(res,nums,pos+1,temp);
        temp.pop_back();
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>res;
        vector<int>temp;
        f(res,nums,0,temp);
        vector<vector<int>>ans;
        for(auto it : res){
            ans.push_back(it);
        }
        return ans;
    }
};