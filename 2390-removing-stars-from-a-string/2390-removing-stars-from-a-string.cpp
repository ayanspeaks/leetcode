class Solution {
public:
    string removeStars(string s) {
    string ans;                 //Desired answer string
    for(char i:s){              //Copying input string
        if(i=='*')  
            ans.pop_back();     //Removed rightmost string character as soon as '*' is found
        else
            ans+=i;                     
    }
    return ans;
}
};