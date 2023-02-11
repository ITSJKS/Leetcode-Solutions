class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        int mask = 0;
        for(int i = 31; i>=0; i--){
            unordered_set <int> prefix_set;
            mask = mask | (1<<i);
            for(auto x:nums){
                prefix_set.insert(x&mask);
            }
            int temp = result | (1<<i);
            for(auto prefix:prefix_set){
                if(prefix_set.count(temp^prefix)){
                    result = temp;
                    break;
                }
            }
        }
        return result;
    }
};