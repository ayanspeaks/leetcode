class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int cost=0,maxLen=0;
        for(int i=0,j=0;j<n;j++)
        {
            cost+=abs(s[j]-t[j]);
            while(i<=j and cost>maxCost)
            {
                cost-=abs(s[i]-t[i]);
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        }

        return maxLen;
    }
};