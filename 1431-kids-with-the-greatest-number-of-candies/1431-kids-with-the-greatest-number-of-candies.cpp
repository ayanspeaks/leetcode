class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        vector<bool> out;
        int max = *max_element(c.begin(), c.end());
        
        for(int i = 0; i < c.size(); i++){
            if(c[i] + ec >= max){
               out.push_back(true); 
            }
            else{
                out.push_back(false);
            }
        }
        return out;
    }
};