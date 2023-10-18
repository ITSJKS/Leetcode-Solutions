class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n);
        int ans = 0;
        stack <int> st;
        for(int i = n-1; i >=0; i--){
            int cnt = 0;
            while(!st.empty() && nums[i] > nums[st.top()]){
                dp[i] = max(dp[i]+1,dp[st.top()]);
                st.pop();
                ans = max(ans,dp[i]);
            }
            st.push(i);
        }
        return ans;
    }
};