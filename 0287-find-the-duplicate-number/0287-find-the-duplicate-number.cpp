class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto check = [&](int cur){
            int count = 0;
            for(auto x:nums){
                if(x <= cur) count++;
            }
            return count;
        };
        int l= 0 , r = nums.size()+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid) > mid) r = mid;
            else l = mid;
        }
        return r;
    }
};