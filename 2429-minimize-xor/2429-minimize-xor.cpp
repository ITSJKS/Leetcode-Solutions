class Solution {
public:
    int minimizeXor(int nums1, int nums2) {
        int set_1 = __builtin_popcount(nums1);
        int set_2 = __builtin_popcount(nums2);
        int ans = 0;
        
        for(int i = 31; i>=0; i--){
            if(nums1&(1<<i) && set_2){
                ans|=1<<i;
                set_2--;
            }
        }
        for(int i = 0; i <=31; i++){
            int set = (1<<i)&nums1;
            if(set_2>0 && !set ){
                ans|=1<<i;
                set_2--;
            }
        }
        return ans;
    }
};