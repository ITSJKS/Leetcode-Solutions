class Solution {
    int total = 0;
    vector <int> subset;
public:
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums,0);
        return total;
    }
    void backtrack(vector <int> &nums,int start){
        if(start == nums.size()){
            total += calc_xor(subset);
            return;
        }
        subset.push_back(nums[start]);
        backtrack(nums,start+1);
        subset.pop_back();
        backtrack(nums,start+1);
    }
    int calc_xor(vector <int> &nums){
        int x = 0;
        for(auto y:nums){
            x^=y;
        }
        return x;
    }
};