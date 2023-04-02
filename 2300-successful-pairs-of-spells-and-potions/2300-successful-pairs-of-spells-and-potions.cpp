class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        vector <int> ans(n);
        int m = potions.size();
        for(int i = 0; i < n; i++){
            long long sp = spells[i];
            long long req = ceil(success/(1.0*sp));
            // cout<<req<<" ";
            int cnt = lower_bound(potions.begin(),potions.end(),req)-potions.begin();
            cout<<cnt<<" ";
            ans[i] = m - cnt;
        }
        return ans;
    }
};