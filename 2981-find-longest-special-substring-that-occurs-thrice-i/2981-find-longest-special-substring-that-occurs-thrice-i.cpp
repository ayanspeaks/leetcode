class Solution {
public:

    int maximumLength(string s) {
        unordered_map<string,int>mp;

        for(int i = 0 ; i < s.length(); i++){
            string temp = "";
            temp += s[i];
            mp[temp]++;
            for(int j = i+1 ; j < s.length() ; j++){
                if(s[i] == s[j]){
                    temp += s[j];
                    mp[temp]++;
                }
                else{
                    break;
                }
               
                
            }
        }

        int size = INT_MIN;
        for(auto it : mp){
            if(it.second >= 3 ){
                int val = it.first.size();
                size = max(val,size);
            }
        }

        return size == INT_MIN ? -1 : size;
    }
};