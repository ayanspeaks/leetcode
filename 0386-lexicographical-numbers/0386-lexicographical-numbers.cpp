class Solution {
public:

    void solve(int i, int n,vector<int> &v){
        //base case
        if(i>n) return; // if the number choosen is larger than n that is out of bound and we return

        //recersive case
        v.push_back(i); // we push the i when it is in the range
        for(int j=0;j<=9;j++){
            solve(i*10+j,n,v); // after insert the i we move to the next number starting with i and check for all possibility and insert them 
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<10;i++){
            solve(i,n,ans); // we have to insert the number in order from 1 to 9 so we use the loop for it and will insert all the number starting with this digit before moving ahead
        }
        return ans;
    }
};