class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> idxArr(100, 0);
        for (int i = 0; i < nums.size(); i++) {
            idxArr[nums[i] - 1]++;
            if (idxArr[nums[i] - 1] > 2) {
                return false;
            }
        }
        return true;
    }
};