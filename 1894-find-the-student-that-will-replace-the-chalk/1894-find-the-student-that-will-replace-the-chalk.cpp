class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector <long long> prefix(n,0);
        prefix[0] = chalk[0];
        for(int i = 1; i <n; i++){
            prefix[i]+=prefix[i-1]+chalk[i];
        }
        k = k%prefix[n-1];
        auto it = upper_bound(prefix.begin(),prefix.end(),k)-prefix.begin();
        return it;
   }
};