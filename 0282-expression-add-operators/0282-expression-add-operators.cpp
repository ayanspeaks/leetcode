class Solution {
public:


vector<string> ans;

string num;
int target;

vector<string> addOperators(string num, int target) {
    
    this->num = num;
    
    this->target = target;
    
    backtrack( 0, "", 0, 0);
    
    return ans;
}
void backtrack(int i, const string& path, long resSoFar, long prevNum) {
    
    if (i == num.size()) {
        
        if (resSoFar == target)   
        {
            ans.push_back(path);
            
        }
        
        return;
    
    }
    
    string numStr;
    
    long num1 = 0;
    
    for (int j = i; j < num.length(); j++) {
        
        if (j > i && num[i] == '0')
        {
            break;
        }
        numStr += num[j];
        
        num1 = num1 * 10 + num[j] - '0';
        
        if (i == 0) {
            
            backtrack(j + 1, path + numStr, num1, num1);
            
        } else {
            
            backtrack(j + 1, path + "+" + numStr, resSoFar + num1, num1);
            
            backtrack(j + 1, path + "-" + numStr, resSoFar - num1, -num1);
            
            backtrack(j + 1, path + "*" + numStr, resSoFar - prevNum + prevNum * num1, prevNum * num1);
        }
    }
}
};