class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector <int> dp(n,1);
        vector <int> hash(n,0);
        int maxi = 1, last_index = 0;
        for(int i = 0; i <n; i++){
            hash[i] = i;
            for(int j = 0; j <i; j++){
                if(nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                last_index = i;
            }
        }
        vector <int> temp;
        temp.push_back(nums[last_index]);
        while(hash[last_index]!=last_index){
            last_index = hash[last_index];
            temp.push_back(nums[last_index]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};