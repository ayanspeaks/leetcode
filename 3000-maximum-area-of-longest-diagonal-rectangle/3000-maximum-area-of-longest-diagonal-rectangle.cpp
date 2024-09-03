class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=0, len=0;
        for (auto rect: dimensions){
            int d= (rect[0]*rect[0])+(rect[1]*rect[1]);
            if (d>len){
                len=d;
                area= rect[0]*rect[1];
            }else if (d==len){
                area= max(area,rect[0]*rect[1]);
            }
        }
        return area;
    }
};