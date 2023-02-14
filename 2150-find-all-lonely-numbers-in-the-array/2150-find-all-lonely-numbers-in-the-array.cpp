class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector <int> count(1e6+1,0);
        for(auto x:nums) count[x]++;
        vector <int> ans;
        for(auto x:nums){
            if(x == 0 && !(count[x+1] || count[x] >1)) ans.push_back(x);
            else if(x == 1000000 && !(count[x-1] || count[x]>1)) ans.push_back(x);
            else if((x>0 && x < 1000000) && count[x-1] == 0 && count[x+1] == 0 && count[x] == 1) ans.push_back(x);
        }
        return ans;
    }
};
