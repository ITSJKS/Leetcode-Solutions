class Solution {
public:
    int area_rect(int x1,int y1, int x2,int y2){
        int l = abs(x2-x1);
        int b = abs(y2-y1);
        return l*b;
    }
    int common_area(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
        int b = min(ay2,by2) - max(ay1,by1);
        int l = min(ax2,bx2) - max(ax1,bx1);
        if(b > 0 && l > 0){
            return b*l;
        }
        return 0;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        return area_rect(ax1,ay1,ax2,ay2) + area_rect(bx1,by1,bx2,by2) - common_area(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2);
    }
};