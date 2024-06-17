class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> count;
        unordered_map<int,bool> check;
        for(int i=0;i<arr.size();i++) count[arr[i]]++;
        for(auto i : count){
            if(check[i.second]==true) return false;
            check[i.second]=true;
        }
        return true;
    }
};