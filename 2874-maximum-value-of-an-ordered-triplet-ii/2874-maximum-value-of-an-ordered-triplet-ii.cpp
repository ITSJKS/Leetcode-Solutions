class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        multiset <int> st;
        st.insert(nums[0]);
        int diff = 0;
        for(int i = 1; i <n; i++){
            if(i >1){
                ans = max(ans,diff*1ll*nums[i]);
            }
            diff = max(diff,*st.rbegin()-nums[i]);
            st.insert(nums[i]);
        }
        return ans;
    }
};