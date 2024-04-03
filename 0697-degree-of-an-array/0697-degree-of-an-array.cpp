class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> degree;
        // storing max degree
        int m = 0;
        // storing length of subarray
        int k = nums.size();

        for(int i=0; i<nums.size(); i++) {
            // assign vector of size 2 for every new element
            // 1- degree of the element 2- first position of element
            if(degree.find(nums[i]) == degree.end())
                degree[nums[i]] = vector<int>(2);
            
            // increment degree of the element and
            // if its first occurred than fill its first position
            if(++degree[nums[i]][0] == 1)
                degree[nums[i]][1] = i;

            // update degree of array and length of subarray when
            // degree of the element is greater
            if(degree[nums[i]][0] > m) {
                m = degree[nums[i]][0];
                k = i - degree[nums[i]][1] + 1;
            }
            // update k when there are elements with same max degree
            else if(degree[nums[i]][0] == m)
                k = min(k, i - degree[nums[i]][1] + 1);
        }
        return k;
    }
};