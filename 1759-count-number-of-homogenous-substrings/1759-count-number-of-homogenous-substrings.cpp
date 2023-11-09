class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        long long count = n;
        int cnt = 0;
        for(int i = 1; i <n; i++){
            if(s[i]==s[i-1]){
                cnt++;
                count = (count + cnt)%mod;
            }
            else{
                cnt = 0;
            }
        }
        return count;
    }
};