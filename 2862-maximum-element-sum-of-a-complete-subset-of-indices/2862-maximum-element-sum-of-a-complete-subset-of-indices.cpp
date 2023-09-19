class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 1; i <=n; i++){
            long long cur = 0;
            for(int v = 1; v*v*i <=n; v++){
                cur += nums[v*v*i - 1];
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};

/*
Maximum element sum of a complete subset of indices
a set of numbers is complete if product of every pair of it's element is a perfect square

for a subset of indices set {1,2....n} -> element sum as {nums[i1] + nums[i2] + nums[i3] + .... + nums[ik]}

8 7 3 5 7 2 4 9
1 2 3 4 5 6 7 8

for each index i we can find all those indices with which it will form a complete subset

              8 -> 8 2
              



*/