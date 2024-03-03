class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque <long long> dq;
        // sum of the subarray will be greater than k if
        // prefix[r] - prefix[l-1] >= k  , ans = r-l+1
        int n = nums.size();
        long long cur = 0;
        long long ans = 1e9;
        dq.push_back(0ll);
        vector <long long> prefix(n+1,0);
        for(int r = 1; r<=n; r++){
            cur += nums[r-1];
            while(dq.size() && (cur - prefix[dq.front()]) >= k){
                ans  = min(ans,r-dq.front());
                dq.pop_front();
            }
            while(dq.size() && cur < prefix[dq.back()]) dq.pop_back();
            prefix[r] = cur;
            dq.push_back(r);
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};