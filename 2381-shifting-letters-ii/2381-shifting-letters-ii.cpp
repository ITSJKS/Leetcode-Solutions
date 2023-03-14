class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector <int> prefix(n+1);
        for(auto x:shifts){
            int l = x[0] ,r = x[1] , type = x[2];
            if(type){
                prefix[l]++;
                prefix[r+1]--;
            }
            else{
                prefix[l]--;
                prefix[r+1]++;
            }
        }
        for(int i = 1; i <=n; i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i = 0; i <n; i++){
            int ch = s[i]-'a';
            prefix[i]%=26;
            int n_ch = (ch + prefix[i] + 26)%26;
            s[i] = n_ch + 'a';
        }
        return s;
    }
};