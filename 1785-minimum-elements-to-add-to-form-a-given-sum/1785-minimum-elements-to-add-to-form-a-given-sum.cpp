class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        long long req = abs(goal - sum);
        return (req+limit-1)/limit;
    }
};