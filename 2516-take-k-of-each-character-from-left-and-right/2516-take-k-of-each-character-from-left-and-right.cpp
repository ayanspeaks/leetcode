class Solution {
public:
    int takeCharacters(string s, int k) {
        
        int m=s.size(), counta=0, countb=0, countc=0, i=0;

        if(k==0)
            return k;
            
        while(i<m){
            if(s[i]=='a')
                counta++;
            else if(s[i]=='b')
                countb++;
            else
                countc++;
            
            i++;
        }

        if(counta < k || countb < k || countc < k)
            return -1;

        i=m-1;
        int ans=INT_MAX, j=m;
        while(i>=0){
            if(s[i]=='a'){
                if(counta-1 >= k)
                    counta--;
                else
                    break;
            }
            else if(s[i]=='b'){
                if(countb-1 >= k)
                    countb--;
                else
                    break;
            }
            else if(s[i]=='c'){
                if(countc-1 >= k)
                    countc--;
                else 
                    break;
            }
            i--;
            ans= min(ans, counta+countb+countc);
        }

        while(j>0){
            j--;
            if(s[j]=='a')
                counta++;
            else if(s[j]=='b')
                countb++;
            else if(s[j]=='c')
                countc++;

            while(i>=0){
                if(s[i]=='a'){
                    if(counta-1 >= k)
                        counta--;
                    else
                        break;
                }
                else if(s[i]=='b'){
                    if(countb-1 >= k)
                        countb--;
                    else
                        break;
                }
                else if(s[i]=='c'){
                    if(countc-1 >= k)
                        countc--;
                    else 
                        break;
                }
                i--;
                ans= min(ans, counta+countb+countc);
            }   
        }
        return ans;
    }
};