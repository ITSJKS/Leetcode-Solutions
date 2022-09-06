class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0] >0) return {};
        vector <vector <int>> ans;
        int n = nums.size();
        for(int i = 0; i <n; i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]== nums[i-1]) continue;
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
                int val = nums[i]+nums[low]+nums[high];
                if(val < 0) low++;
                else if(val>0) high--;
                else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    int last = nums[low],last_h = nums[high];
                    while(low < high && nums[low]==last){
                        low++;
                    }
                    while(low < high && nums[high]!=last_h) high++;
                }
            }
            
        }
        return ans;
    }
};