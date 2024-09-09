class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        
        priority_queue<long long> pq;
        
        for(int &x: gifts) pq.push(x);
        
        while(k--){
            long long topp = pq.top();
            pq.pop();
            
            long long y = sqrt(topp);
            //cout<<y<<" ";
            pq.push(y);
        }
        
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};