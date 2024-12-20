class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());//sort krle bahi
        int cnt=0;
        int start=0,end=n-1;//pointer set krle
        if(n==0||power<tokens[0])//edge condition lagale
        {
            return 0;
        }
        while(start<=end)//pointers cross na kre
        {
            if(power>=tokens[start])//face down ki condition
            {
                power-=tokens[start];
                tokens[start]=0;//uss point pe array ko hata dio
                start++;
                cnt++;
            }
            else if(power<tokens[start]&&cnt>0&& start < end)//face up
            {
                power+=tokens[end];
                tokens[end]=0;
                end--;
                cnt--;
            }
            else {//agar kuc nhi krskte to break lelete hai
                break;
            }
        }return cnt;//cnt return krlete hai
    }
};