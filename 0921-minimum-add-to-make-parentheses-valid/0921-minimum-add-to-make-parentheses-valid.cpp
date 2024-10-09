class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0,cnt=0;
        for(auto i:s)
        {
            if(i=='(')
            size++;
            else
            {
                if(size!=0)
                size--;
                else
                cnt++;
            }
        }
        return cnt+size;
    }
};