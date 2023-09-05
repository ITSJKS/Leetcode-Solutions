class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        vector <int> a, b;
        for(int i = 0; i <n; i++){
            if(i <n/2) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        vector <vector <int>> left(16);
        int s1 = a.size();
        int s2 = b.size();
        for(int bit = 0; bit<(1<<s1); bit++){
            int s = 0, cnt = __builtin_popcount(bit);
            for(int j = 0; j <s1; j++){
                if(bit&(1<<j)) s += a[j];
            }
            left[cnt].push_back(s);
        }
        vector <unordered_set <int>> right(16);
        for(int bit = 0; bit<(1<<s2); bit++){
            int s = 0, cnt = __builtin_popcount(bit);
            for(int j = 0; j <s2; j++){
                if(bit&(1<<j)) s += b[j];
            }
            right[cnt].insert(s*n);
        }
        for(int i = 0; i <=s1; i++){
            for(auto s:left[i]){
                for(int size = max(i,1); size < i + s2; size++){
                    int l_cnt = i;
                    int r_cnt = size - i;
                    if(right[r_cnt].count(sum*size - n*s)) return true;
                }
            }
        }
        return false;
    }
};