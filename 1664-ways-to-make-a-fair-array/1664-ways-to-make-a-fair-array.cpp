class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd_sum = 0;
        int n = nums.size();
        int even_sum = 0;
        for(int i = 0; i <n; i++){
            if(i&1) odd_sum += nums[i];
            else even_sum += nums[i];
        }
        // the logic is , we will check from behind, if we remove the current element , we know that the odd_sum after the current elment is now even_sum and vice versa, so if the sum are equal we can say that the current idx can make it a fair array
        int odd_behind = 0;
        int even_behind = 0;
        int count = 0;
        for(int i = n-1; i>=0; i--){
            if(i%2 == 0){
                even_sum -= nums[i];
            }
            else odd_sum -= nums[i];
            if(even_sum + odd_behind  == odd_sum + even_behind) count++;
            if(i&1) odd_behind += nums[i];
            else even_behind += nums[i];
        }
        return count;
    }
};

// even odd even odd even odd even
// --------------even--- -> even sum , odd sum
// if we remove this even element , cur_element should not be added 