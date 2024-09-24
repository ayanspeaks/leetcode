class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int ans=0;
        
        unordered_map<string,int>mp;
        
        for(int i=0;i<n1;i++){
            string s=to_string(arr1[i]);
            string temp;
            for(int j=0;j<s.length();j++){
                temp.push_back(s[j]);
                mp[temp]++;
            }
            temp.clear();
        }
       
        
            for(int i=0;i<n2;i++ ){
                 string s=to_string(arr2[i]);
                string temp;
            for(int j=0;j<s.length();j++){
                temp.push_back(s[j]);
//cout<<temp<<" "<<"ALOK"<<endl;
                if(mp[temp]){
                    int z=temp.length();
                    ans=max(ans,z);}
            }
                temp.clear();
                
            }
        
        return ans;
        
    }
};