class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector <vector <int>> freq(k,vector <int>(1025,0));
        for(int i = 0; i <n; i++){
            freq[i%k][nums[i]]++;
        }
        vector <vector <int>> dp(k+1,vector <int>(1025,1e9));
        dp[0][0] = 0;
        // dp[i][j] = minimum number of changes to get xor of j using first i elements
        for(int i = 0; i <k; i++){
            int total = (n+k-1-i)/k;
            int mini_change = *min_element(dp[i].begin(),dp[i].end());
            for(int target = 0; target<=1024; target++){
                dp[i+1][target] = total + mini_change;
                for(int index = i; index < n; index+=k){
                    int picked = nums[index];
                    int previous = picked^target;
                    if(previous > 1024) continue;
                    dp[i+1][target] = min(dp[i+1][target],dp[i][previous] + total - freq[i][picked]);
                }
            }
        }
        return dp[k][0];
    }
};

// make xor of all segment equal to zero
/*
we need to find minimum number of elements to change in the array such that the xor of all segments of size k is equal to zero.
it is given that nums[i] < 2^10
so we have to think of only 10 bits
size of k is 2000
we can think of in bits for making each segment equal to zero -> It can become zero only if each bit's in the segment is set even number of times
so we have to check for each segment if the number of set bits in the segment is even or not , if not 
nums[i] == nums[i+k]
*/