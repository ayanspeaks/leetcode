class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> arr(26,vector<long long>(26,INT_MAX));
        int n=original.size();

        for(int i=0;i<n;i++){
            arr[original[i]-'a'][changed[i]-'a']=min((long long)cost[i],arr[original[i]-'a'][changed[i]-'a']);
        }
        for(int via=0;via<26;via++){
	        for(int i=0;i<26;i++){
	            for(int j=0;j<26;j++){
	                arr[i][j]=min(arr[i][j],arr[i][via]+arr[via][j]);
	            }
	        }
	    }

        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]-'a'==target[i]-'a') continue;
            long long val=arr[source[i]-'a'][target[i]-'a'];
            if(val==INT_MAX) return -1;
            ans+=val;
        }
        return ans;
    }
};