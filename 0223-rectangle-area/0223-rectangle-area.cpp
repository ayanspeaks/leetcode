class Solution {
public:
int computeArea (int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    
     int rect1= (ax2-ax1) *(ay2-ay1); 
     int rect2 = (bx2-bx1) *(by2-by1);
if (ax2<=bx1 || ax1>=bx2 || by1>=ay2 || by2<=ay1){
return rect1+rect2;
}
int max_common_x = max(ax1,bx1);
int max_common_y = max(ay1, by1);
int min_common_x = min(ax2, bx2);
int min_common_y = min(ay2, by2);
return rect1 + rect2 - (min_common_x-max_common_x) * (min_common_y-max_common_y);
}
};