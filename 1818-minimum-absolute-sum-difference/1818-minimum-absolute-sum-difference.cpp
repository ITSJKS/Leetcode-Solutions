class Solution {
public:
    int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector <long long> prefix(n);
        set <int> st;
        long long sum = 0;
        for(int i = 0; i <n; i++){
            prefix[i] = abs(nums1[i]-nums2[i]);
            st.insert(nums1[i]);
            sum = (sum+prefix[i]);
        }
        long long ans = sum;
        for(int i = 0; i <n; i++){
            long long temp = sum;
            temp = (temp - prefix[i]);
            auto it = st.upper_bound(nums2[i]);
            if(it!=st.begin()){
                auto it1 = it;
                it1--;
                ans = min(ans,(temp + abs(*it1-nums2[i])));
            }
            ans = min(ans,(temp + abs(*it - nums2[i])));
            
        }
        return ans%mod;
    }
};