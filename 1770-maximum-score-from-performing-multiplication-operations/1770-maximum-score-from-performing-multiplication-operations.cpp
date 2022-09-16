class Solution {
    int dp[1001][1001];
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        for(auto &x:dp){
            for(auto &y:x){
                y = INT_MIN;
            }
        }
        return find_maxi(nums,multipliers,0,n-1,0);
    }
    int find_maxi(vector <int> &nums, vector <int> &mul, int i, int j, int a){
        if(i>j || a == mul.size()) return 0; 
        if(dp[i][a]!=INT_MIN) return dp[i][a];
        return dp[i][a] = max(nums[i]*mul[a]+find_maxi(nums,mul,i+1,j,a+1),nums[j]*mul[a]+ find_maxi(nums,mul,i,j-1,a+1));
    }
};