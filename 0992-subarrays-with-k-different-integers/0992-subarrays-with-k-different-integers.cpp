class Solution {
public:
    int subarraysWithKDistinct(vector<int>& fruits, int k) {
        unordered_map <int,int> mp;
        int n = fruits.size();
        int l = 0;
        int ans = 0;
        int prefix  = 0;
        for(int r = 0; r <n; r++){
            mp[fruits[r]]++;
            while(mp.size() > k && l <= r){
               if(mp[fruits[l]] == 1) mp.erase(fruits[l]);
               l++;
               prefix = 0;
                
            }
            while(mp[fruits[l]]>1){
                mp[fruits[l]]--;
                l++;
                prefix++;
            }
            if(mp.size() == k)
                ans += 1 + prefix;
        }
        return ans;
    }
};