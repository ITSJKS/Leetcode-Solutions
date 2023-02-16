class Solution {
public:
    unordered_map <string,int> mp;
    int solve(int idx, int count,vector <int> &s, int n){
        if(idx >= n ) return 0;
        string mask = to_string(idx) + "#" + to_string(count);
        if(mp.count(mask)) return mp[mask];
        int take = 0;
        take = max(take,s[idx]*count + solve(idx+1,count+1,s,n));   
        int not_take = solve(idx+1,count,s,n);
        return mp[mask] = max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // vector <int> dp(n+1,vector <int>(500001,-1));
        return solve(0,1,satisfaction,n);
    }
};