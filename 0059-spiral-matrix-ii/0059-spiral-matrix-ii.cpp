class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i, j, o, k, num;
        vector<vector<int>> vec(n, vector<int>(n));
        for (i = j = o = 0 , num = 1; num <= (n * n) && i < n - o; o++, i++, j++) {
            cout << vec[i][j] << endl;
            while (j < n - o) {
                if (num > n*n) break;
                vec[i][j++] = num++;
            }
            j--;
            for (k = i + 1; k < n - o; k++) {
                if (num > n*n) break;
                vec[k][j] = num++;
            }
            k--;
            while (j > o) {
                if (num > n*n) break;
                vec[k][--j] = num++;
            }
            while (k > i + 1) {
                if (num > n*n) break;
                vec[--k][o] = num++;
            }
            
        }
        return vec;
    }
};