class Solution {
public:
    int minBitFlips(int start, int goal) {
         int sxorg = start ^ goal;
        int count = 0;
        while(sxorg != 0) {
            int rsb = sxorg & -sxorg;
            sxorg -= rsb;
            count++;
        }
        return count;
    }
};