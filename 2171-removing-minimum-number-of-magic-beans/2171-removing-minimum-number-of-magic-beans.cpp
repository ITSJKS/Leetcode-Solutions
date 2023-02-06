class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        int n = beans.size();
        long long sum = accumulate(beans.begin(),beans.end(),0ll);
        long long count = sum;
        for(int i = 0; i <n; i++){
            count = min(count,sum - 1ll*beans[i]*(n-i));
        }
        return count;
    }
};