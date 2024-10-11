class Solution {
public:
    typedef pair<int, int> pii;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int arrivalTime = times[targetFriend][0];
        int n = times.size();
        priority_queue<int, vector<int>, greater<int>> freeSeats;
        priority_queue<pii, vector<pii>, greater<pii>> pq; // {departureTime, seat}
        int maxUsedSeat = 0;
        sort(times.begin(), times.end());
        for(int i = 0; i < n; i++) {
            int at = times[i][0];
            int dt = times[i][1];
            int currSeat;
            while(!pq.empty()) {
                pii tp = pq.top();
                if(tp.first <= at) {
                    freeSeats.push(tp.second);
                    pq.pop();
                } else {
                    break;
                }
            }
            
            if(freeSeats.size() > 0) {
                currSeat = freeSeats.top();
                freeSeats.pop();
            } else {
                currSeat = maxUsedSeat;
                maxUsedSeat++;
            }
            if(at == arrivalTime) {
                return currSeat;
            }
            pq.push({dt, currSeat});   
        }
        return -1;
    }
};