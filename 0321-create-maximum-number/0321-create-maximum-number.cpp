class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector <int> ans;
        for(int i = max(0,k-m); i<=min(n,k); i++){
            ans = max(ans,combine(solve(nums1,i),solve(nums2,k-i)));
        }
        return ans;
    }
    vector <int> solve(vector <int>&nums, int k){
        int n = nums.size();
        vector <int> v;
        for(int i = 0; i <n; i++){
            while(v.size() && v.back() < nums[i] && v.size()+n-i>k){
                v.pop_back();
            }
            if(v.size() < k) v.push_back(nums[i]);
        }
        return v;
    }
    vector<int> combine(vector<int> vec1,vector<int> vec2){
        vector<int> ans;
        while(vec1.size()+vec2.size()){
            vector<int>& now = vec1>vec2?vec1:vec2;
            ans.push_back(now[0]);
            now.erase(now.begin());
        }
        return ans;
    }
};
/*
maximum number of length k from digits of the two numbers.
*/