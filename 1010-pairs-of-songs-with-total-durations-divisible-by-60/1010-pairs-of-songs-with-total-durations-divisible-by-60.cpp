class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map <int,int> mp;
        int n = time.size();
        long long count = 0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j <=1000; j+=60){
                count += mp[j-time[i]];
            }
            mp[time[i]]++;
        }
        return count;
    }
};