class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> sub;
        for(auto x:nums){
            if(sub.size() == 0 || sub.back()<x) sub.push_back(x);
            else{
                auto it = lower_bound(sub.begin(),sub.end(),x);
                *it = x;
            }
        }
        return sub.size();
    }
};