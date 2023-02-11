class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        int mask = 0;
        for(int i = 31; i>=0; i--){
            unordered_set <int> prefix_set;
            mask = mask | (1<<i);
            int temp = result | (1<<i);
            for(auto x:nums){
                if(prefix_set.count(x&(mask)^temp)){
                    result = temp;
                    break;
                }
                prefix_set.insert(x&mask);
            } 
        }
        return result;
    }
};