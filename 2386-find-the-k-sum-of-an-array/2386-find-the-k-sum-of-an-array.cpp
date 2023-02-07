class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long total_sum = 0;
        for(auto &x:nums){
            if(x>0) total_sum += (long long)x;
            else x = abs(x);
        }
        cout<<total_sum<<" ";
        sort(nums.begin(),nums.end());
        typedef pair <long long,int> pii;
        priority_queue <pii> pq;
        pq.push({total_sum-(long long)nums[0],0});
        while(!pq.empty() && k>1){
            long long sum  = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(idx < n-1){
                pq.push({sum-nums[idx+1],idx+1});
                pq.push({sum-nums[idx+1]+nums[idx],idx+1});
            }
            k--;
            total_sum = sum;
        }
        return total_sum;
    }
};