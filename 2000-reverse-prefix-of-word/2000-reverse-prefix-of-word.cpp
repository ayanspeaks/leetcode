class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=-1;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                index=i;
                break;
            }
        }
        if(index!=-1) reverse(word.begin(),word.begin()+1+index);
        return word;
    }
};