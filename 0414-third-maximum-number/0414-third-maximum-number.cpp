class Solution {
public:
int thirdMax(vector<int>& nums) {
           set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()>=3){    
            int Third_index_from_last=s.size()-3;
            auto third_maximum=next(s.begin(),Third_index_from_last);
            return *third_maximum;
        }
            return *--s.end(); 
    }
};
