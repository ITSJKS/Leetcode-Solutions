class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        for(int i = 0; i <n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int cur = nums[i];
            int l = i+1, h = n-1;
            while(l<h){
                int val = nums[l]+nums[h] + cur;
                if(val == target){
                    return val;
                }
                if(abs(val-target)<abs(ans-target)){
                    ans = val;
                }
                if(val <= target){
                    l++;
                }
                else{
                    h--;
                }
                
            }
        }
        return ans;
    }
};