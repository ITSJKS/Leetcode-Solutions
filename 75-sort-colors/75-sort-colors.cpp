class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = -1, white = -1, blue = -1;
        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                nums[++red] = 2,nums[++white] = 1,nums[++blue] = 0;
            }
            else if(nums[i] == 1){
                nums[++red] = 2,nums[++white] = 1;
            }
            else{
                nums[++red] = 2;
            }
        }
    }
};