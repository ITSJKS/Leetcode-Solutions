class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector <int> prefix(n+1,0);
        vector <int> suffix(n+1,0);
        for(int i = 1; i <=n; i++){
            if(s[i-1] == '1'){
                prefix[i] = min(prefix[i-1]+2,i);
            }
            else{
                prefix[i] = min(prefix[i-1],i);
            }
            if(s[n-i] == '1'){
                suffix[i] = min(suffix[i-1]+2,i);
            }
            else{
                suffix[i] = min(suffix[i-1],i);
            }
        }
        int ans  = 1e8;
        for(int i = 1; i <=n; i++){
            ans = min(ans,prefix[i] +suffix[n-i]);
        }
        return ans;
    }
};