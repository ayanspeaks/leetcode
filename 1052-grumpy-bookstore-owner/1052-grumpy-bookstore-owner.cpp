static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int m) {
        int c=0,ans=0,mx=0,sum=0;
        for(int i=0;i<customers.size();i++)
        {
            c++;
            if(!grumpy[i])
            {
                ans+=customers[i];
            }
            else sum+=customers[i];
            if(c>m)
            {
                c--;
                if(grumpy[i-c]) sum-=customers[i-c];
                
            }
            mx=max(mx,sum);
        }
        return ans+mx;
    }
};