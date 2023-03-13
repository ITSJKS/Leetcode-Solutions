class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // two ways
        vector <int> pos,neg;
        int n = nums.size();
        for(auto x:nums){
            if(x > 0) pos.push_back(x);
            else neg.push_back(x);
        }
        int c = 0;
        for(int i = 0; i <n; i++){
            if(i%2) nums[i] = neg[c],c++;
            else nums[i] = pos[c];
        }
        return nums;
    }
};