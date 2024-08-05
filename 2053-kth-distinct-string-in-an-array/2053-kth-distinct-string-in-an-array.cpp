class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        vector<string> distinct;

        for(auto str:arr)
            mp[str]++;

        for(auto str:arr){
            if(mp[str]==1)
                distinct.push_back(str);
        }
        if(k>distinct.size())
            return "";
        return distinct[k-1];

    }
};