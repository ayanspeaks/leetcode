class Solution {
public:
    bool wordPattern(string p, string s) 
    {
        vector<string>v;
        string a;
        stringstream ss(s);
        while(ss>>a) v.push_back(a);

        if(p.size() != v.size()) return false;

        map<char,string>mp;
        map<string,char>mp2;
        int i = 0, n = p.size();
        while(i<n)
        {
            if(mp[p[i]].empty()) 
            {
                if(mp2[v[i]] != NULL) return false;
                mp[p[i]] = v[i];
                mp2[v[i]] = p[i];
            }
            else if(mp[p[i]] != v[i]) return false;
            i++;
        }
        return true;
    }
};