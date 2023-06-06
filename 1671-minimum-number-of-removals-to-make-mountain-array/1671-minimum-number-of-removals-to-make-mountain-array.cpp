class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector <int> left(n,1);
        vector <int> right(n,1);
        for(int i = 1; i <n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && left[i] < left[j] + 1){
                    left[i] = left[j]+1;
                }
            }
        }
        for(int i = n-2; i>=0; i--){
            for(int j = n-1; j>i; j--){
                if(nums[i] > nums[j] && right[i] < right[j]+1){
                    right[i] = right[j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <n-1; i++){
            if(left[i] > 1 && right[i] > 1)
            ans = max(ans,left[i]+right[i]-1);
        }
        return n - ans;
    }
};

// we can store minimum number of element to remove to make array upto idx i an increasing array 
// also another array which keeps number of element to remove to make array upto idx i from n-1 an decreasing array
// answer will be sum of both at any idx

// 2 1 1 5 6 2 3 1
// left increasing removal
// 0 1 2 2 2 3 4 5
// right increasing removal
// 5 4 3 2 1 1 0 0

// answer will be 
// 5 5 5 4 3 4 4 5 => 3