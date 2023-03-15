class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n);
        int ans = 0;
        stack <int> st;
        for(int i = n-1; i >=0; i--){
            while(!st.empty() && nums[i] > nums[st.top()]){
                dp[i] = max(dp[i]+1,dp[st.top()]); // dp[st.top()] needed to find if there is already a better answer;
                ans = max(ans,dp[i]);
                st.pop();
            }
          st.push(i);
        }
        return ans;
    }
};