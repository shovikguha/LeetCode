class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ax2 - ax1) * (ay2 - ay1);
        int a2 = (bx2 - bx1) * (by2 - by1);
        
        if(ax2 < bx1 || bx2 < ax1){
            return a1 + a2;
        }
        if(ay2 < by1 || by2 < ay1){
            return a1 + a2;
        }
        int x = abs(max(ax1, bx1) - min(ax2, bx2));
        int y = abs(min(ay2, by2) - max(ay1, by1));
        
        
        return a1 + a2 - (x*y);
    }
};