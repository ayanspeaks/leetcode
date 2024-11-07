class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        //Here the idea is to create a map with cards[i] and opisition i if we found such elemnt for which cards[i] is alreday present in map so find the min length as res
        unordered_map<int,int>m;
        int res=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(m.find(cards[i])!=m.end()){
                res=min(res,i-m[cards[i]]+1);
            }
            m[cards[i]]=i;            
        }

        if(res!=INT_MAX){
            return res;
        }else
        return -1;
        
    }
};