class Solution {
public:
    int minimumPushes(string word) {
        int Count = 0, Len = 0;
        int Size = size(word);
        vector<int> New(26, 0);
        for (int i=0; i<Size; i++){
            New[word[i] - 'a']++;
        }    
        sort(New.begin(), New.end(), [] (auto &a, auto &b){return  a > b;});
        int Sum = 0;
        for (auto m : New){
            if (Len%8==0){
                Count++;
            }
            Len++;
            Sum += Count * m;
        }
        return Sum;
    }
};