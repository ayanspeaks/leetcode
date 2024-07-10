class Solution {
public:
    string reverseVowels(string s) {
          int n=s.length();
        if(n==1)
            return s;
        vector<bool> vis(n,false);
        string vow="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='A'||s[i]=='i'||s[i]=='I'||s[i]=='e'||s[i]=='E'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
            {
                vis[i]=true;
                vow+=s[i];
            }
        }
        reverse(vow.begin(),vow.end());
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==true)
            {
                s[i]=vow[j];
                j++;
            }
        }
        return s;
    }
};