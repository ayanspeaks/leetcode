class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1){
            if(set.count(n)) return false;
            set.insert(n);
            
            int next=0;
            while(n>0){
                int tmp=n%10;
                next+=tmp*tmp;
                n=n/10;
            }
            n=next;
        }
        return true;
    }
};