class Solution {
    vector <vector <int>> powerset;
    vector <int> subset;
public:
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums,0);
        int sum = 0;
        for(auto x:powerset){
            sum += calc_xor(x);
        }
        return sum;
    }
    void backtrack(vector <int> &nums,int start){
        if(start == nums.size()){
            powerset.push_back(subset);
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