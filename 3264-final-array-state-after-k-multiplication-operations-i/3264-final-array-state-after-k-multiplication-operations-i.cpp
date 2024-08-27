class Solution {
public:  

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
         
         // creating a minHeap with pair which will store {nums_element,index}
          priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > minHeap;

          int n=nums.size();
          vector<int> ans(n); // to return the final answer

          for(int i=0;i<n;i++) {
              minHeap.push({nums[i],i}); // heapify
          }
      
       // repeat the process k times
           for(int i=0;i<k;i++){
               int val=minHeap.top().first; // taking the smallest element
               int index=minHeap.top().second; // index of the samllest element
               minHeap.pop();  // removing that element bcz we have to update 
               minHeap.push({val*multiplier,index}); // pushing the updated element to minHeap
           }

          
// placing all the element to the ans array, according to their index
          while(!minHeap.empty()){
                ans[minHeap.top().second]=minHeap.top().first;
                minHeap.pop();
          }  
          return ans;  
    }
};