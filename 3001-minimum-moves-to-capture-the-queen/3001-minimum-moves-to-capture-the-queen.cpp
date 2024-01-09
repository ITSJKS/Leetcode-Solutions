class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int dx = a;
        int dy = b;
       while(dx <= 8){
           if(dx == e && dy == f) return 1;
           if(dx == c && dy == d) break;
           dx++;
       }
        dx = a,dy = b;
       while(dy <= 8){
           if(dx == e && dy == f) return 1;
           if(dx == c && dy == d) break;
           dy++;
       }
        dx = a,dy = b;
        while(dx >=1){
           if(dx == e && dy == f) return 1;
           if(dx == c && dy == d) break;
           dx--;
       }
        dx = a,dy = b;
       while(dy >= 1){
           if(dx == e && dy == f) return 1;
           if(dx == c && dy == d) break;
           dy--;
       }
        dx = c,dy = d;
        while(dx <= 8 && dy <= 8){
           if(dx == e && dy == f) return 1;
           if(dx == a && dy == b) break;
           dx++,dy++;
       }
        dx = c,dy = d;
        while(dx >=1 && dy >= 1){
           if(dx == e && dy == f) return 1;
           if(dx == a && dy == b) break;
           dx--,dy--;
       }
        dx = c,dy = d;
        while(dx >=1 && dy <= 8){
           if(dx == e && dy == f) return 1;
           if(dx == a && dy == b) break;
           dx--,dy++;
       }
        dx = c,dy = d;
        while(dx <=8 && dy >= 1){
           if(dx == e && dy == f) return 1;
           if(dx == a && dy == b) break;
           dx++,dy--;
       }
        return 2;
    
    }
};