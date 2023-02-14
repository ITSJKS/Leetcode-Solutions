class Solution {
public:
    bool check(int mid, vector <int> &nums,int k){
        long long  count = 0;
        for(auto x:nums){
            count += (x-1)/mid;
            if(count > k) return false;
        }
        return count <= k;
    }
    int minimumSize(vector<int>& nums, int k) {
        int l = 0 , r = 1e9+1;
        // sort(nums.begin(),nums.end());
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid,nums,k)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return r;
    }
};