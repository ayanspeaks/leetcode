class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()==1||s.length()==2)
          return s;


        string ans;
        int i;
        for(i=0;i<=s.length()-3;i++)
        {
            if(s[i]==s[i+1]&&s[i+1]==s[i+2])
               continue;
            else
               ans.push_back(s[i]);
        }

        ans.push_back(s[i]);
        ans.push_back(s[++i]);


        return ans;

        
    }
};