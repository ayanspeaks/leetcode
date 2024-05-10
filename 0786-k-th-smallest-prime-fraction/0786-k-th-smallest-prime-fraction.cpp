class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> maxHeap;

        for(int i=0;i<arr.size()-1;i++) {
            for(int j=i+1;j<arr.size();j++) {
                double val = double(arr[i])/double(arr[j]);
                if(maxHeap.size() < k) {
                    maxHeap.push({val,{arr[i],arr[j]}});
                } else {
                    if(maxHeap.top().first > val) {
                        maxHeap.pop();
                        maxHeap.push({val,{arr[i],arr[j]}});
                    }
                }
            }
        }
        vector<int> ans;
        pair<int,int> p = maxHeap.top().second;
        ans.push_back(p.first);
        ans.push_back(p.second);

        return ans;
    }
};