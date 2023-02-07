class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums,k) - atmostK(nums,k-1);
    }
    
    int atmostK(vector <int> &nums, int k){
        unordered_map <int,int> mp;
        int n = nums.size();
        int count = 0;
        for(int r = 0,l = 0; r <n; r++){
            mp[nums[r]]++;
            if(mp.size()<=k) count += r - l + 1;
            
            while(mp.size()>k && l<=r){
                if(mp[nums[l]] == 1) mp.erase(nums[l]);
                else mp[nums[l]]--;
                l++;
                if(mp.size()<=k){
                    count += r - l + 1;
                    break;
                }
            }
            
        }
        return count;
        
    }
};