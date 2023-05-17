class Solution {
public:
    long long appealSum(string s) {
        long long cur_sum = 0;
        vector <int> freq(26,0);
        for(int i =1 ; i <=s.size(); i++){
            freq[s[i-1]-'a'] = i;
            for(auto &x:freq) cur_sum += x;
        }
        return cur_sum;
    }
};