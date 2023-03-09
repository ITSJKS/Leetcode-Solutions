class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        while(nums.size()>1){
            n = nums.size();
            vector <int> v;
            int zeroes = 0;
            for(int i =1; i <n; i++){
                int num = (nums[i]+nums[i-1])%10;
                zeroes += (num == 0);
                v.push_back(num);
            }
            if(v.size() == zeroes) return 0;
            nums = v;
            ans = nums[0];
        }
        return  ans;
    }
};