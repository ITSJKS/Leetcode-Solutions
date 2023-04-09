class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map <long long ,pair<long long,int>> mp;
        int n = nums.size();
        vector <long long> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = abs(mp[nums[i]].second*1ll*i - mp[nums[i]].first);
            mp[nums[i]].first += i;
            mp[nums[i]].second ++;
        }
        mp.clear();
        for(int i = n-1; i>=0; i--){
            ans[i] += abs(mp[nums[i]].second*1ll*i - mp[nums[i]].first);
            mp[nums[i]].first += i;
            mp[nums[i]].second ++;
        }
        return ans;
    }
};