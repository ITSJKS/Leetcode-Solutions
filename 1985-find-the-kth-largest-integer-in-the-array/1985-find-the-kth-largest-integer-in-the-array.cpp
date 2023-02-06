class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        auto cmp = [&](string &a, string &b){
            if(a.size() == b.size()) return a < b;
            if(a.size() < b.size()) return true;
            return false;
        };
        sort(nums.begin(),nums.end(),cmp);
        return nums[n-k];
    }
};