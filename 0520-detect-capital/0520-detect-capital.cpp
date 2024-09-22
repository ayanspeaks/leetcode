class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int count1=0, count2=0, count3=0;

        for(auto x: word){
            if(x>=65 and x<=90) count1++;
            //for all capital letters

            if(x>=97 and x<=122) count2++;
            //for all small letters
            
            if(word[0]>=65 and word[0]<=90){
                //check only when first word is capital
                if(x>=97 and x<=122) count3++;
            }
        }
        
        if(count1==n) return true;
        else if(count2==n) return true;
        else if(count3==n-1) return true;
        return false;
    }
};