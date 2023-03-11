class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector <int> ans(k);
        unordered_map <int,set <int>> mp;
        for(auto x:logs){
            mp[x[0]].insert(x[1]);
        }
        unordered_map <int,int> mp2;
        for(auto x:mp){
            mp2[x.second.size()]++;
        }
        for(int i = 0; i <k; i++){
            ans[i] = mp2.count(i+1)?mp2[i+1]:0;
        }
        return ans;
    }
};