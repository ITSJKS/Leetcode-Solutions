class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long increase = 0,decrease = 0;
        long long sum1 = 0, sum2 = 0;
        int n = nums1.size();
        if(k == 0) return nums1 == nums2?0:-1;
        for(int i = 0; i <n; i++){
            int y = (nums1[i]-nums2[i]);
            if(y>=0){
                if(y%k) return -1;
                increase += y;
            }
            else{
                y = abs(y);
                if(y%k) return -1;
                decrease += y;
            }
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        if(increase == decrease && sum1 == sum2) return increase/k;
        return -1;
    }
};