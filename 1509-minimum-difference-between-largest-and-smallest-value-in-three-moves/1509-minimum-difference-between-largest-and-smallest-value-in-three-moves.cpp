class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 5) return 0;
        std::sort(nums.begin(), nums.end());
        int a = nums[n-4] - nums[0];  
        int b = nums[n-3] - nums[1];  
        int c = nums[n-2] - nums[2];  
        int d = nums[n-1] - nums[3];  
        return std::min({a, b, c, d});
    }
};