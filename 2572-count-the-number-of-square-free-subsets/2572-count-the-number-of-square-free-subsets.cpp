#define ll long long
class Solution {
public:
    int dp[1001][1025];
    vector <int> primes = {2,3,5,7,11,13,17,19,23,29};
    const int mod = 1e9 + 7;
    ll solve(vector <int> &nums,int ind, int mask){
        if(ind == nums.size()) return 1;
        if(dp[ind][mask]!=-1) return dp[ind][mask];
        bool flag = 1;
        int new_mask = mask;
        for(int j = 0; j <10; j++){
            int count = 0;
            int num = nums[ind];
            while(num%primes[j] == 0){
                num/=primes[j];
                count++;
            }
            if(count>=2 || (count == 1 && mask&(1<<j))){
                flag = 0;
                break;
            }
            if(count) new_mask |= 1<<j;
        }
        // take case
        int take = 0;
        if(flag) take = solve(nums,ind+1,new_mask)%mod;
        
        // not_take case
        int not_take = solve(nums,ind+1,mask)%mod;
        return dp[ind][mask] = (take + not_take)%mod;
    }
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return solve(nums,0,0)-1;
    }
};