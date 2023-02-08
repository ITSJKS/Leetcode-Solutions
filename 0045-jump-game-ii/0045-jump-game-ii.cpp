class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int max_step  = 0;
        int current = 0;
        for(int i = 0; i <n-1; i++){
            max_step = max(max_step,i + nums[i]);
            if(current == i){
                current = max_step;
                step++;
            }
                    
            }
    return step;
    }
};