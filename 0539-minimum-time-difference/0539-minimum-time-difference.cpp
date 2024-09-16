class Solution {
public:
    int findMinDifference(vector<string>& t) {
        sort(t.begin(),t.end());
        int n = t.size(),mindiff,hoursdiff,minutesdiff;
        mindiff = (23-(t[n-1][0]-48)*10-(t[n-1][1]-48))*60+60-(t[n-1][3]-48)*10-(t[n-1][4]-48)+
        ((t[0][0]-48)*10+(t[0][1]-48))*60+(t[0][3]-48)*10+(t[0][4]-48);
        for(int i = 0;i<n-1;i++)
        {
            hoursdiff = ((t[i+1][0]-48)*10+(t[i+1][1]-48)-(t[i][0]-48)*10-(t[i][1]-48)-1)*60;
            minutesdiff =  60-(t[i][3]-48)*10-(t[i][4]-48)+(t[i+1][3]-48)*10+(t[i+1][4]-48);
            mindiff = min(mindiff,hoursdiff+minutesdiff);
        }
        return mindiff;
    }
};