class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;  // the furthest index that can be reached
        
        for(int i = 0; i < n; i++) {
            // If the current index is greater than the furthest reachable index, return false
            if(reachable < i) {
                return false;
            }
            // Update the furthest reachable index
            reachable = max(reachable, i + nums[i]);
        }
        // If we can reach or pass the last index, return true
        return true;
    }
};
