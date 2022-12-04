#define ll long long int
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll left = 0, right= 0, val;
        for(int i : nums) left += (ll)i;
        int n = nums.size(), curr = left/n, res = n - 1;
        for(int i=n-1;i>=1;i--) {
            left -= nums[i], right += nums[i];
            val = abs(left/(i) - right/(n - i));
            if(curr >= val) {
                curr = val, res = i-1;
            }
        }
        return res;
    }
};