class Solution {
    bool isEqual(int l,int r)
    {
        if(l==r || (l>='A' && l<='Z' && r==l+32)
          || (r>='A' && r<='Z' && l==r+32))
            return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int r = s.size();
        if(r==0)
            return true;
        
        vector<int> vec;
        int i=0;
        while(i<r)
        {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
                vec.push_back(s[i]);
            i+=1;
        }
        
        int l=0;
        r = vec.size();
        while(l<r)
        {
            if(isEqual(vec[l],vec[r-1])==false)
                return false;
            ++l;
            --r;
        }
        return true;
    }
};