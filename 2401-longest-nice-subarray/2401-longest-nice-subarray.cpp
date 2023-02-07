class Solution {
public:
    bool check(int x, int y){
        for(int i = 0; i <32; i++){
            if((x&1<<i) && (y&1<<i)) return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int cur_and = 0;
        for(int r = 0,l = 0; r < n; r++){
            while(!check(cur_and,nums[r]) && l <= r){
                    cur_and ^= nums[l];
                    l++;
                }
            cur_and  |= nums[r];
            maxi = max(maxi,r-l+1);
            
        }
        return maxi;
    }
};