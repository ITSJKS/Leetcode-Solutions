class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map <int,int> mp;
        int maxi = 0;
        int sum = 0;
        for(int r = 0, l = 0; r<nums.size(); r++){
            sum += nums[r];
            mp[nums[r]]++;
            while(l < r && mp.size()!=r-l+1){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                sum -= nums[l];
                l++;
                }
            if(mp.size() == r-l+1)
                maxi = max(maxi,sum);
        }
        return maxi;
    }
};