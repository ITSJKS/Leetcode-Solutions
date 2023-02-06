class Solution {
public:
    int shortestSubarray(vector<int>& num, int k) {
        vector <long long> nums(num.begin(),num.end());
        long long n = nums.size();
        deque <int> d;
        int res = n + 1;
        for(int i = 0; i <n; i++){
            if(i > 0){
                nums[i]+=nums[i-1];
            }
            if(nums[i]>=k) res = min(res,i+1);
            while(d.size()>0 && nums[i]-nums[d.front()]>=k) 
                res = min((int)res,(int)i-d.front()),d.pop_front();
            while(d.size()>0 && nums[i]<nums[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return res<=n?res:-1;
    }
};