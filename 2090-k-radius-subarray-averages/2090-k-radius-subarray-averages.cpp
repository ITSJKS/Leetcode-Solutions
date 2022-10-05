class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 2*k+1;
        vector <int> ans(n,-1);
        long long sum = 0;
        for(int i = 0; i <n; i++){
            sum += nums[i];
            if(i >=l){
                sum-=nums[i-l];
            }
            if(i>=l-1)
              ans[i-k] = sum/l;
            
        }
        return ans;
        
    }
};