class Solution {
public:
    typedef long long ll;
    ll mod = INT_MAX;
    ll dp[201];
    ll fact(int n)
    {
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (n*fact(n-1))%mod;
    }

    ll pow(ll a, ll b)
    {
        if(!b) return 1;
        ll m = pow(a, b/2);
        m = (m*m)%mod;
        if(b&1) m = (m*a)%mod;
        return m;
    }

    ll inv(ll a)
    {
        return pow(a, mod-2);
    }

    ll nCr(ll a, ll b)
    {
        ll n1 = fact(a);
        ll d1 = inv(fact(a-b));
        ll d2 = inv(fact(b));
        d1 = (d1*d2)%mod;
        return (n1*d1)%mod;
    }
    int uniquePaths(int m, int n) 
    {
        memset(dp, -1, sizeof(dp));
        fact(200);
        dp[0] = 1;
        return nCr(m+n-2, m-1);
    }
};