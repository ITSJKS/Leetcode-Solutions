class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, h = n, ans = 0;
        long mid , need;
        while(l<=h){
            mid = l + (h-l)/2;
            need = (mid * (mid+1))/2;
            if(need <= n) l = mid + 1, ans = mid;
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};