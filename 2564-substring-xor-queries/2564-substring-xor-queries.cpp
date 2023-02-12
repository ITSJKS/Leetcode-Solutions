class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map <int,vector<int>> mp;
        for(int i =0; i <n; i++){
            long long val = 0;
            for(int j = i; j < n; j++){
                val = (val<<1) +(s[j]=='1');
                if(val >= INT_MAX) break;
                if(mp.find(val) == mp.end()){
                    mp[val] = {i,j};
                }
                if(s[i] == '0') break;
            }
        }
        vector <vector <int>> ans;
        for(auto q:queries){
            int first = q[0], second = q[1];
            if(mp.find(first^second)!=mp.end()){
                ans.push_back(mp[first^second]);
            }
            else{
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};