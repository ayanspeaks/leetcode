class Solution {//easy peasy 
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Calculate the total chalk needed for one full round
        long long totalChalk = 0;
        for (int c : chalk) {
            totalChalk = totalChalk + c;
        }
        
        // Reduce k by the total chalk used in complete rounds
        k = k % totalChalk;
        
        // Find the student who will need to replace the chalk
        for (int i = 0; i < chalk.size(); ++i) {
            if (chalk[i] > k) {
                return i;
            }
            k = k - chalk[i];
        }
        
        // This point should never be reached due to constraints
        return 0;
    }
};