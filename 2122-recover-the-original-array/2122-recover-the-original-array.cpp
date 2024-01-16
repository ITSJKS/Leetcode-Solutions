class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map <int,int> mp;
        for(auto &x:nums) mp[x]++;
        int sm = nums[0];
        int n = nums.size();
        for(int j = 1; j <n; j++){
            int k = nums[j]-sm;
            if(k <= 0 || k&1) continue;
            unordered_map <int,int> temp = mp;
            bool check = true;
            vector <int> ans;
            for(int i = n-1; i>=0; i--){
                if(temp.count(nums[i]) == 0) continue;
                temp[nums[i]]--;
                if(temp[nums[i]] == 0) temp.erase(nums[i]);
                if(temp.count(nums[i]-k)){
                    temp[nums[i]-k]--;
                    if(temp[nums[i]-k] == 0) temp.erase(nums[i]-k);
                    ans.push_back((nums[i]+nums[i]-k)/2);
                }
                else{
                    check = false;
                    break;
                }
            }
            if(check && temp.size() == 0){
                return ans;
            }
        }
        return {};
    }
};
// we are given an array of size 2*n
// sum of our required array is sum(nums)/2

// sum of lower is req - n*d
// sum of upper is req + n*d

// a , a + d
// b , b + d
// c , c + d