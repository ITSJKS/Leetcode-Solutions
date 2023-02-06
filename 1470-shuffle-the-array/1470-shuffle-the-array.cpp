class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int first = 0, second = n;
        int maxi  = 2000;
        for(int i = 0; i <2*n; i++){
            if(i%2 == 0){
                nums[i] = (nums[first++]%maxi)*maxi + nums[i];
            }
            else{
                nums[i] = (nums[second++]%maxi)*maxi + nums[i];
            }
        }
        for(int i = 0; i <2*n; i++){
            nums[i]/=maxi;
        }
        return nums;
    }
};