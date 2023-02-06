class Solution {
public:
    int binary_search(vector <int> &nums,int l,int r, int target){
        while(r - l >1){
            int mid = l + (r-l)/2;
            if(nums[mid]<target) l = mid;
            else r = mid;
        }
        return r;
    }
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                int k = binary_search(nums,j,n,nums[i]+nums[j]);
                count+=k-j-1;
            }
        }
        return count;
    }
};