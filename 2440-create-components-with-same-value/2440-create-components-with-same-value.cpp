class Solution {
public:
    int dfs(vector <int> &nums, vector <vector <int>> &g, int src, int par, int target){
        int cur_sum = nums[src];
        for(auto &nbr:g[src]){
            if(nbr == par) continue;
            cur_sum += dfs(nums,g,nbr,src,target);
        }
        if(cur_sum == target) return 0;
        return cur_sum;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector <vector <int>> g(n);
        for(auto &x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        unordered_set <int> st(nums.begin(),nums.end());
        if(st.size() == 1) return n-1;
        for(int i = n-1; i>1; i--){
            if(sum %i) continue;
            int req_sum = sum/i;
            int check = dfs(nums,g,0,-1,req_sum);
            if(check == 0) return i -1;
        }
        return 0;
        
    }
};