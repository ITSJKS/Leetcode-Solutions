class Solution {
public:
    int totalMoney(int n) {
        int cur = 1;
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(i>1 && i%7 == 1) cur = cur-6;
            count += cur;
            cur++;
        }
        return count;
    }
};