class Solution {
public:
    int tribonacci(int n) {
        int t1 = 0, t2 = 1, t3 = 1;
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 1;

        int res = 0;
        for (int i = 3; i <= n; i++)
        {
            res = t1 + t2 + t3;
            t1 = t2;
            t2 = t3;
            t3 = res;
        }
        
        return res;
    }
};