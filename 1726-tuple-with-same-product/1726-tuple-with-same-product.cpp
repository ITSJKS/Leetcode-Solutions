class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map <int,int> mp;
        int n = nums.size();
        for(int i = 0; i <n; i++){
            for(int j = i+1; j < n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        long long count = 0;
        for(auto x:mp){
            count += 8*(x.second)*(x.second-1)/2;
        }
        return count;
                   
    }
};