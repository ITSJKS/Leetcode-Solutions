class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long even_sum = 0;
        for(auto x:nums){
            if(x%2 == 0)
            even_sum += x;
        }
        vector <int> q;
        for(auto y:queries){
            int val = y[0];
            int idx = y[1];
            if(nums[idx]%2 == 0){
                even_sum -= nums[idx];
            }
            nums[idx] += val;
            if(nums[idx]%2 ==0 ) even_sum+= nums[idx];
            q.push_back(even_sum);
        }
        return q;
    }
};