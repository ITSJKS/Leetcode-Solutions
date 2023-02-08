class Solution {
public:
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = mapping.size();
        vector <pair <int,int>> v;
        int i = 0;
        for(auto &x:nums){
            string s = to_string(x);
            for(auto &y:s){
                y = mapping[y-'0'] + '0';
            }
            int y = stoi(s);
            v.push_back({y,i});
            i++;
        }
        auto cmp = [&](pair <int,int> v1, pair <int,int> v2){
        if(v1.first == v2.first) return v1.second < v2.second;
        return v1.first < v2.first;
    };
        sort(v.begin(),v.end(),cmp);
        int m = nums.size();
        vector <int> ans;
        for(auto x:v){
            ans.push_back(nums[x.second]);
        }
        return ans;
    }
};