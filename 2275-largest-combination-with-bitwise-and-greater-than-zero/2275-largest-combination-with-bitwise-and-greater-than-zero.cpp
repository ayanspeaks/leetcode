class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi=*max_element(candidates.begin(),candidates.end());
        int len=log2(maxi);
        int maxCount=0;
        for(int i=0;i<=len;i++)
        {
            int count=0;
            int num=pow(2,i);
            for(int j:candidates)
            {
                if(j&num)count++;
            }
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};