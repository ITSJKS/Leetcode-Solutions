class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i = 0, j = (int)nums.size()-1;
        int count = 0;
        long long l_sum = 0;
        long long r_sum = 0;
        while(i < j){
            if(l_sum + (long long)nums[i] == r_sum + (long long)nums[j]){
                l_sum = 0;
                r_sum = 0;
                i++;
                j--;
            }
            else if(l_sum + (long long )nums[i] < r_sum + (long long)nums[j]){
                l_sum += (long long)nums[i];
                i++;
                count++;
            }
            else{
                r_sum += (long long)nums[j];
                j--;
                count++;
            }
        }
        return count;
        
    }
};
// in palindrome 1 2 3 4 3 2 1
// so we need to make first and last equal then only we can continue ahead
// if we can make them equal then we need to make 