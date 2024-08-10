class Solution {
public:
    vector<int> fa;
    
    int getfa(int x) {
        if (x == fa[x])
            return x;
        fa[x] = getfa(fa[x]);
        return fa[x];
    }
    
    void unify(int x, int y) {
        int a = getfa(x), b = getfa(y);
        if (a != b)
            fa[a] = b;
    }
    
    int regionsBySlashes(vector<string>& g) {
        int n = g.size();
        int tot = n * n * 2;
        
        fa = vector<int>(tot+1);
        for (int i = 1; i <= tot; ++i)
            fa[i] = i;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int a = (i*n + j) * 2 + 1;
                int b = a + 1;
                
                if (g[i][j] == ' ')
                    unify(a, b);
                
                if (j < n-1) {
                    int x = g[i][j] == '/' ? b : a;
                    int y = g[i][j+1] == '/' ? b+1 : b+2;
                    unify(x, y);
                }
                
                if (i < n-1)
                    unify(b, a + 2*n);
            }
        
        int ans = 0;
        for (int i = 1; i <= tot; ++i)
            if (fa[i] == i)
                ++ans;
        
        return ans;
    }
};