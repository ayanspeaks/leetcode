class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            v[i]=i+1;
        }
        int start=0;
        k--;
        while(v.size()>1)
        {
            int i=(start+k)%v.size();
            v.erase(v.begin()+i);
            start=i;
        }
        return v[0];
    }
};