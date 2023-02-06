class Solution {
public:
    void dfs(int node, vector <int> &seen, vector <int> children[],vector <int> &nums){
        seen[nums[node]] = 1;
        for(auto c:children[node]){
            if(seen[nums[c]] ==0 ) dfs(c,seen,children,nums);
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        vector  <int> res(n,1);
        vector <int> seen(100005,0);
        int ind_1 = -1;
        int i = 0;
        for(auto x:nums){
            if(x == 1) ind_1 = i;
            i++;
        }
        if(ind_1 == -1) return res;
        vector <int> children[n];
        for(int i = 1; i <n; i++){
            children[parents[i]].push_back(i);
        }
        i = ind_1;
        int small = 2;
        while(i>=0){
            dfs(i,seen,children,nums);
            while(seen[small]) small++;
            
            res[i] = small;
            i = parents[i];
            
        }
        return res;
    }
};