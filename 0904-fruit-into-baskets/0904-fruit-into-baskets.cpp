class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map <int,int> mp;
        int n = fruits.size();
        int l = 0;
        int ans = 0;
        for(int r = 0; r <n; r++){
            mp[fruits[r]]++;
            while(mp.size()>2 && l <= r){
                int x = mp[fruits[l]];
                x--;
                if(x == 0){
                mp.erase(fruits[l]);
                }
                else{
                    mp[fruits[l]] = x;
                }
                l++;
            }
            if(mp.size() <= 2){
                ans = max(ans,r-l+1);
            }
            
        }
        return ans;
    }
};