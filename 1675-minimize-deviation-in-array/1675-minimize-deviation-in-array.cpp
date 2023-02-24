class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // first remove all the greater from the array
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minii = nums[0];
        int maxi = nums[n-1];
        int diff = maxi - minii;
        if(diff == 0) return 0;
        int mini = INT_MAX;
        priority_queue <int> pq;
        for(auto x:nums){
            if(x&1) pq.push(2*x),mini = min(mini,2*x);
            else pq.push(x),mini = min(mini,x);
        }
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            diff = min(diff,top-mini);
            if(top&1) break;
            pq.push(top/2);
            mini = min(mini,top/2);
        }
        return diff;
       
    }
};