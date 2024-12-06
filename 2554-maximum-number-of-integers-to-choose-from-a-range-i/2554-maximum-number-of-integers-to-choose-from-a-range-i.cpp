class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
     int sum = 0;
     int count = 0;
     for(int i = 1 ; i <= n ; i++){
         if( sum+i <= maxSum){
             if(find(banned.begin(),banned.end(),i)==banned.end()){
                 sum+=i;
                 count++;
             }
         }
        } 
     return count;  
    }
};