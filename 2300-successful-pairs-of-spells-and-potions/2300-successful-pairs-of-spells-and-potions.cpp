class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& p, long long s) { 
        
        vector<int>ans(spells.size(),0);
        int n=spells.size();
        int m=p.size();
        sort(p.begin(),p.end());
        for(int i=0;i<spells.size();i++){
        int low=0;
        int high=p.size()-1;

            long long  cs=spells[i];
            int cr=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(cs*p[mid]<s){
                    low=mid+1;
                }else if(cs*p[mid]>=s){
                    high=mid-1;
                    cr=mid;
                }
            }
            if(cr!=-1){
                ans[i]=p.size()-cr;
            }
        }
        return ans;
    }
};