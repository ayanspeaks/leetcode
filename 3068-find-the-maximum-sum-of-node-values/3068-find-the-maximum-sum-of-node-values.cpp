class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
         priority_queue<int> pq;
        long long ans = 0;
        for(int i : nums) {
            ans += i;
            pq.push((i ^ k) - i);
        }
        while(pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a + b > 0)
                ans += a + b;
        }
        return ans;
    }
};