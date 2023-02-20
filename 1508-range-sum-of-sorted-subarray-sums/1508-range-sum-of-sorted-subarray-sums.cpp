class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector <long long> prefix(n+1);
        for(int i =1; i <=n; i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }
        vector <long long> ans;
        for(int i =1; i<=n; i++){
            for(int j = i; j <=n; j++){
                ans.push_back(prefix[j]-prefix[i-1]);
            }
        }
        sort(ans.begin(),ans.end());
        long long sum = 0;
        for(int i = left-1; i <right; i++){
            sum = (sum + ans[i])%mod;
        }
        return sum%mod;
    }
};