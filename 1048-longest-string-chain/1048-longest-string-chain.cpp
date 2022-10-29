 bool comp(string &s1,string &s){
        return s1.size()<s.size();
    }
class Solution {
public:
    bool check(string &s1, string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int first = 0, second = 0;
        while(first<s1.size()){
            if(s1[first] == s2[second] && second  < s2.size()){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        return first == s1.size() && second == s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector <int> dp(n,1);
        int maxi = 1;
        for(int i =0; i <n; i++){
            for(int j = 0; j <i; j++){
                if(check(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                }
                maxi = max(dp[i],maxi);
                
            }
        }
        return maxi;
    }
};