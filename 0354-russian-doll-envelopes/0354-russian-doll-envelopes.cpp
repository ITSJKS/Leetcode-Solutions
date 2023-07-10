class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        auto cmp = [&](vector <int>&a, vector <int>&b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(env.begin(),env.end(),cmp);
        vector <int> prev;
        for(int r = 0; r < env.size(); r++){
            int num = env[r][1];
            if(prev.size() == 0 || prev.back() < num) prev.push_back(num);
            else{
                auto it = lower_bound(prev.begin(),prev.end(),num);
                *it = num;
            }
        }
        return prev.size();
    }
};
// It is an simple one