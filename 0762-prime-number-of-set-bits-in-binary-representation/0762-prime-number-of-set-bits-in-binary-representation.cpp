class Solution {
public:
    int solve(int a)
    {
        int ans=0;
        while(a>0)
        {
            if(a%2==1)ans++;

            a/=2;
        }
        return ans;
    }
    bool isprime(int a)
    {
        if(a==1)return false;
        for(int i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int a=solve(i);
            if(isprime(a)==true)
            {
                ans++;
            }
        }
        return ans;
    }
};