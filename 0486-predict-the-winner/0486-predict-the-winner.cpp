class Solution {
public:
    int solve(int start, int end, int turn , vector <int> &nums){
        if(start == end) return turn*nums[start];
        int a = nums[start]*turn + solve(start+1,end,-turn,nums);
        int b = nums[end]*turn + solve(start,end-1,-turn,nums);
        return turn*max(turn*a,turn*b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(0,n-1,1,nums)>=0;
        
    }
};