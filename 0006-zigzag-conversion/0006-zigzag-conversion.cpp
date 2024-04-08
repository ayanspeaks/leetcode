class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        
        if(numRows == 1)
            return s;
        
        if(numRows >= len){
            return s;
        }
        
        int delta = -1;
        
        int row = 0;
        
        vector<char> res[numRows];
        
        for(auto c:s){
            
            res[row].push_back(c);
            
            if(row == 0 or row == numRows - 1){
                delta *= -1;
            }
            
            row += delta;
        }
        
        string result = "";
        
        for(auto x:res)
            for(auto y:x)
                result += y;
        
        return result;
                
    }
};