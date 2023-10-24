class Solution {
public:
    int longestAwesome(string s) {
        vector <int> v;
        for(int i = 0; i <(1<<10); i++){
            int cnt = __builtin_popcount(i);
            if(cnt == 1 || cnt == 0) v.push_back(i);
        }
        unordered_map <int,int> masks;
        int cur_mask  = 0;
        masks[cur_mask] = -1;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i <n; i++){
            cur_mask ^= (1<<(s[i]-'0'));
            for(auto &x:v){
                int temp = cur_mask^x;
                if(masks.count(temp)) ans = max(ans,i-masks[temp]);
            }
            if(masks.count(cur_mask) == 0){
                masks[cur_mask] = i;
            }
        }
        return ans;
    }
};
/*
if len is even
all must be even
if len is odd
all must be even except one
we need to find longest awesome substring
I need to think in terms of freqmask
s consists only of digits
so there will be just 10 digits
so we can keep a prefix mask
where we will store the mask when reaching a point then we will check
of all the masks that I can have only handful of them will be valid as we can only create a palindrome if the number of odd occuding character is 1 or all r even ones
so I can just all 1024 combinations out of those 100 would be valid now at every point I can go through all these 100 ones and check if there is one available before with me if there is one , I will keep r -l + 1 in my answer
*/