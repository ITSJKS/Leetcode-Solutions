class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(),nums1.end(),0);
        int sum2 = accumulate(nums2.begin(),nums2.end(),0);
        if(sum1 == sum2) return 0;
        if(sum1 > sum2) swap(sum1,sum2),swap(nums1,nums2);
        int diff = sum2 - sum1;
        vector <int> arr;
        for(auto &x:nums1){
            arr.push_back(6-x);
        }
        for(auto &x:nums2){
            arr.push_back(x-1);
        }
        sort(arr.begin(),arr.end(),greater<int>());
        int count = 0;
        for(auto &x:arr){
            diff -= x;
            count++;
            if(diff <= 0) return count;
        }
        return -1;
    }
};