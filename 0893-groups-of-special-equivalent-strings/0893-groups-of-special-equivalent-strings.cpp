class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map <string,int> mp;
        for(auto x:words){
            int n = x.size();
            string s;
            string t;
            for(int i = 0; i < n; i++){
                if(i%2) t.push_back(x[i]);
                else s.push_back(x[i]);
            }
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            mp[s+t]++;
        }
        return mp.size();
    }
};