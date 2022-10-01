class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr1 = 0,xr2=0;
        for(auto x:nums1) xr1^=x;
        for(auto y:nums2) xr2^=y;
        int n = nums1.size(),m = nums2.size();
        if(n%2 && m%2==0) return xr2;
        else if(n%2 == 0 && m%2) return xr1;
        else if(n%2 == 0 && m%2 == 0) return 0;
        return xr1^xr2;
    }
};