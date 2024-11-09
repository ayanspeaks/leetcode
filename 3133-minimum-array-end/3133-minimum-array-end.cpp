class Solution {
public:
    
    long long minEnd(int n, int x) {
        vector<long long >arr(50,0);
        for(int i = 0;i<50;i++){
            long long re = pow(2,i);
            if( re & x ){
                arr[49-i] = 1; 
            }
        }
        long temp = n-1;
        vector<long long >narr(50,0);
        for(int i = 0;i<50;i++){
            long long re = pow(2,i);
            if(re & temp){
                narr[49-i] = 1;
            }
        }
       
        int z = 49,y=49;
        for(int i = z;i>=0;i--){
            if(arr[i] == 0){
                if(narr[y] == 1){
                    arr[i] = 1;
                }
                y--;
            }
        }
        
        long long num = 0;
        for(int i = 49;i>=0;i--){
            if(arr[i] == 1){
                long long re = pow(2,49-i);
                num = re +num;
            }
        }
        return num;
    }
};