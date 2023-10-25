class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefix(n),suffix(n);
        prefix[0] = nums[0],suffix[n-1] = nums[n-1];
        for(int i = 1; i <n; i++){
            prefix[i] = min(prefix[i-1],nums[i]);
        }
        for(int i = n-2; i>=0; i--){
            suffix[i] = min(suffix[i+1],nums[i]);
        }
        int ans =1e9;
        for(int i = n-2; i>0; i--){
            int left = prefix[i-1];
            int cur = nums[i];
            int right = suffix[i+1];
            if(cur > left && cur >right){
                ans = min(ans, left + cur + right);
            }
        }
        if(ans ==1e9) return -1;
        return ans;
    }
};