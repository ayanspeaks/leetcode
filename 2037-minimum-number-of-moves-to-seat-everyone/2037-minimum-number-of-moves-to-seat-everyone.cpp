class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        // The maximum distance is
        int total_dis = 0;
        for(int i=0; i<seats.size(); i++){
            total_dis += abs(seats[i]-students[i]);
        }

        return total_dis;
    }
};