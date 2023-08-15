class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        auto count = [&](int i){
            string t = to_string(i);
            int res = 0;
            for(auto &x:t) res += x-'0';
            return res;
        };
        unordered_map <int,int> mp;
        int ans = 0;
        for(int i = lowLimit; i <=highLimit; i++){
            ans = max(++mp[count(i)],ans);
        }
        return ans;
    }
};