class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int i = 0;
        int j = 0;
        int maxlen = 0;
        multiset<int> st;
        while(j<nums.size()){
            st.insert(nums[j]);
            int mini = *(st.begin());
            int maxi = *(st.rbegin());
            int l = maxi - mini;
            if(maxi - mini<=limit){
                maxlen = max(maxlen,(j-i+1));
            }
            else 
            {
                while(st.size()>=0 && l>limit){
                    auto it = st.find(nums[i]);
                    st.erase(it);
                    l = *(st.begin()) - *(st.rbegin());
                    i++;
                }
            }
            j++;
        }
        return maxlen;
    }
};