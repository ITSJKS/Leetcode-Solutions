class Solution {
public:
    // unordered_map <pair <int,vector <int>>,int> mp1;
    bool is_unique(vector <int> &v){
        for(auto x:v){
            if(x>1) return false;
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        vector <int> v(26);
         return solve(arr,0,v);
    }
    int solve(vector <string> &arr, int idx, vector <int> &v){
        if(idx == arr.size()) return 0;
        // if(mp1.find({idx,v})!=mp1.end()) return mp1[{idx,v}];
        // don't take it
        int best1 = solve(arr,idx+1,v);
        // take it
        for(auto x:arr[idx]){
            v[x-'a']++;
        }
        int best2 = arr[idx].size() + solve(arr,idx+1,v);
        if(!is_unique(v)) best2 = 0;
        for(auto x:arr[idx]){
            v[x-'a']--;
        }
        return max(best1,best2);
    }
};