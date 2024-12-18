class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
         vector<int>stack;
        int s=prices.size();
        for(int i=0;i<s;i++){
            if(stack.empty() || prices[stack.back()]<prices[i])
                stack.push_back(i);
            else{
                while(!stack.empty() && prices[stack.back()]>=prices[i]){
                    prices[stack.back()]-=prices[i];
                    stack.pop_back();
                }
                stack.push_back(i);
            }
        }
        return prices;
    }
};