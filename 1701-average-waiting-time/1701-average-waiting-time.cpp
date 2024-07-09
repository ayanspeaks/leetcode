class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = customers[0][1];
        int finishtime = customers[0][0] + customers[0][1];
        for (int i = 1; i < customers.size(); i++) {
            int starttime = max(customers[i][0], finishtime);
            finishtime = starttime + customers[i][1];
            ans += finishtime - customers[i][0];
        }
        return ans / customers.size();
    }
};