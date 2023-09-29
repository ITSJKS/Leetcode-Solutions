class Solution {
public:
    map <char,unordered_map <char,int>> mp;
    // bool solve(int ind, int cur, string &s, string &sub){
    //     if(cur == sub.size()) return true;
    //     if(ind == s.size()) return false;
    //     string hash = to_string(ind) + to_string(cur);
    //     if(dp.count(hash)) return dp[hash];
    //     bool ans = false;
    //     char next = sub[cur];
    //     if(s[ind] == next){
    //         ans |= solve(ind+1,cur+1,s,sub);
    //     }
    //     for(auto &x:mp[s[ind]]){
    //         int j = cur;
    //         while(j>0 && x!=sub[j]){
    //             j = lps[j-1];
    //         }
    //         if(x == sub[j]){
    //             j++;
    //         }
    //         ans |= solve(ind+1,j,s,sub);
    //     }
    //     return dp[hash] = ans;
    // }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size();
        int m = sub.size();
        for(auto &x:mappings){
            char u = x[0] , v = x[1];
            mp[u][v] = 1;
        }
        auto check=[&](int i){
            if(i+sub.size()>n) return false;
            int k = 0;
            for(int j = i; j <i+sub.size(); j++){
                if(s[j] == sub[k] || mp[sub[k]][s[j]]) k++;
                else return false;
            }
            return true;
        };
        for(int i = 0 ; i <s.size(); i++){
            if(check(i)) return true;
        }
        return false;        
    }
};

/*
we are given two string s and sub
we are also given 2D character array mappings where mappings[i] = [oldi,newi]
we can perform operation any number of times
replace oldi of sub with newi
we need to make sub a substring of s

intuition
we can change the mapping 
it is given that oldi - > newi 
it also means that new i can be converted by oldi
so for each newi we can push into it oldi
than we can apply kmp on sub
and while traversing the string in dp way 
we can keep a counter of how much sub length we have matched till now
if we are able to match complete sub then we will return true
else we will return false

*/