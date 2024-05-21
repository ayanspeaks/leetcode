class Solution {
public:
    void ip(string&s, vector<string>&ans, int i, int count, string ns){
        if(i==s.length() || count>3) return ;
        if(count==3){
            string num=s.substr(i,s.size()-i);
            if((num[0]=='0' && num.size()==1) || (num[0]!='0' && stol(num)>=0 && stol(num)<=255)){
                string cpy=ns;
                ns+=num;
                ans.push_back(ns);
                ns=cpy;
            }
            return;
        }
        for(int j=i; j<s.length(); j++){
            string num=s.substr(i,j-i+1);
            if((num[0]=='0' && num.size()==1) || (num[0]!='0' && stol(num)>=0 && stol(num)<=255)){
                string cpy=ns;
                ns+=num;
                ns+='.';
                ip(s,ans,j+1,count+1,ns);
                ns=cpy;
            }
            else return;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        ip(s,ans,0,0,"");
        return ans;
    }
};