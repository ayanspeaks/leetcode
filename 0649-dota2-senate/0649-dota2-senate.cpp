class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r;
        queue<int>d;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R')
            {
                r.push(i);
            }
            else
            {
                d.push(i);
            }
        }
        
        int n = senate.length();

        while(true)
        {
            if(r.empty())
            {
                return "Dire";
            }
            if(d.empty())
            {
                return "Radiant";
            }
            int r1 = r.front();
            int d1 = d.front();

            r.pop();
            d.pop();

            if(r1<d1)
            {
                r.push(r1+n);
            }
            else
            {
                d.push(d1+n);
            }
        }
    }
};