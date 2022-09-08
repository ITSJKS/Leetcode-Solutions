class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char ,int> mp;
        int maxi = 0;
        int ans= 0;
        int n = s.length();
        int low = 0;
        for(int i = 0; i <n; i++){
            mp[s[i]]++;
            maxi = max(maxi,mp[s[i]]);
            int cells = i - low +1;
            if(cells - maxi<=k){
               ans = max(ans,cells);
            }
            else{
                mp[s[low]]--;
                if(mp[s[low]] == 0) mp.erase(s[low]);
                low ++;
            }
        }
        return ans;
    }
};