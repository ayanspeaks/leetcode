class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && st.top()=='A' && s[i]=='B'){
                    st.pop();
                }
                else if(!st.empty() && st.top()=='C' && s[i]=='D'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.size();
    }
};