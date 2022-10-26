class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map <int,int> mp;
        mp[0] = -1;
        for(int i = 0; i <n; i++){
            sum += nums[i];
            sum%=k;
            // if(sum == 0 && i) return true;
            if(mp.find(sum)!=mp.end()){
                if(i-mp[sum]>=2) return true;
            }
            else{
                mp[sum] = i;
            }
        }
        return false;
    }
};