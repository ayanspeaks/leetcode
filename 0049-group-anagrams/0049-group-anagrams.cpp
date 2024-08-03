class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Unordered map to store the grouped anagrams
        unordered_map<string, vector<string>> mp;
        
        // Iterate through each string in the input vector
        for(auto x: strs){
            string word = x;
            // Sort the characters in the string to get the key
            sort(word.begin(), word.end());
            // Use the sorted string as the key and append the original string to the map
            mp[word].push_back(x);
        }
        
        // Prepare the result vector to store groups of anagrams
        vector<vector<string>> ans;
        // Iterate through the map and add each group of anagrams to the result
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
