class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    int findTheLongestSubstring(string s) {
        int mask=0,ans=0;
        unordered_map<int,int>m;
        m[mask]=-1;
        for(int i=0;i<s.length();i++){
            if(isvowel(s[i])){
                mask^=s[i];
            }
            if(m.count(mask)==0){
                m[mask]=i;
            }
            else{
                ans=max(ans,i-m[mask]);
            }
        }
        return ans;
    }
};