class Solution {
public:
    int solve(int ind ,int mask , unordered_map <int,int> &masks ,int n,int m,vector <vector <int>>&dp){
        if(mask == (1<<m) - 1) return  0;
        if(ind >= n) return  62;
        if(dp[ind][mask]!=-1) return dp[ind][mask];
        int len = 1e9;
        // take the current people in team
        int new_mask = mask | masks[ind];
        len = min(len,1 + solve(ind+1,new_mask,masks,n,m,dp));
        len = min(len,solve(ind+1,mask,masks,n,m,dp));
        return dp[ind][mask] = len;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map <string,int> mp;
        int m = req_skills.size();
        for(int i = 0; i <m; i++){
            mp[req_skills[i]] = i;
        }
        int n = people.size();
        unordered_map <int,int> masks;
        for(int i = 0; i <n; i++){
            int mask = 0;
            for(auto &x:people[i]) mask |= 1<<mp[x];
            masks[i] = mask;
        }
        vector <vector <int>> dp(n,vector <int>(1<<m,-1));
        int len = solve(0,0,masks,n,m,dp);
        int mask = 0 ;
        int final_mask = (1<<m) - 1;
        vector <int> ans;
        for(int i = 0; i <n; i++){
            if(dp[i][mask]>len){
                ans.push_back(i-1);
                mask |= masks[i-1];
                len--;
            }
            if(i == n-1){
                if(mask != final_mask && (mask | masks[i] == final_mask)) ans.push_back(i);
            }
            if(len == 0) break;
        }
        return ans;
    }
};

// how do I derive the answer by the dp array
// we can start from n-1 and skill ,if the value is equal to diagonal one + 1, then we took this people, and we decrease both i and j else we go back to the minimum of up and left, we do the same for every until we reach n == 0 where we take depending on condition