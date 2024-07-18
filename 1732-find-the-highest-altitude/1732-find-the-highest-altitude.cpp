class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt(gain.size()+1);
        alt[0] = 0;
        for(int i = 0;i < gain.size();i++)
            alt[i+1] = alt[i] + gain[i];
        return *max_element(alt.begin(), alt.end());
    }
};