class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
        return false;
    }
    
    int m = s1.size();
    int n = s2.size();
    bool interleaved[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) {
                interleaved[i][j] = true;
            } else if (i == 0) {
                interleaved[i][j] = interleaved[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            } else if (j == 0) {
                interleaved[i][j] = interleaved[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            } else {
                interleaved[i][j] = (interleaved[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                                    (interleaved[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    
    return interleaved[m][n];
    }
};