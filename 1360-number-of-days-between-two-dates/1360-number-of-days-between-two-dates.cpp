class Solution {
public:
    bool isLeapYear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;

        return false;
    }
    int calculatetototaldays(string date) {
        int days = 0;
        vector<int> hash = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int Y = stoi(date.substr(0, 4));
        int M = stoi(date.substr(5, 2));
        int D = stoi(date.substr(8, 2));

        for (int i = 1971; i < Y; i++) {
            if (isLeapYear(i)) {
                days += 366;
            } else {
                days += 365;
            }
        }
        for (int j = 1; j < M; j++) {
            if (j == 2) {
                days += (isLeapYear(Y)) ? 29 : hash[j];
            } else {
                days += hash[j];
            }
        }
        return days + D;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(calculatetototaldays(date2) - calculatetototaldays(date1));
    }
};
