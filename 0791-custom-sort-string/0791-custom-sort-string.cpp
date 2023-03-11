class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map <char,int> mp;
        int n = order.size();
        for(int i = 0; i <n; i++){
            mp[order[i]] = i+1;
        }
        sort(s.begin(),s.end(),[&](char a, char b){
            return mp[a] < mp[b];}
            );
        return s;
    }
};