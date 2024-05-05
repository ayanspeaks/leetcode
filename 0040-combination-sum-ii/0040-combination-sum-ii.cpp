class Solution {

public:

void findCombination(int index,int target,vector<int>&ds,vector<vector<int>>&ans,vector<int>arr,int n){

    //Base Condition:
    if(target==0){

        ans.push_back(ds);
         return;
    }
   
   
   
  for(int i=index;i<n;i++){

    if((i>index) and  (arr[i]==arr[i-1])){
        continue;
    }

    if(arr[i]>target){
       break;
    }
    ds.push_back(arr[i]);

    findCombination(i+1,target-arr[i],ds,ans,arr,n);

    ds.pop_back();
}


}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      //Here using the same index is not allowed
      int n=candidates.size();
      vector<vector<int>>ans;
      
      vector<int>ds;

      sort(candidates.begin(),candidates.end());

      findCombination(0,target,ds,ans,candidates,n); 

      return ans; 
    }
    
};