class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0, r = n-1;
        set <float> st;
        while(l < r){
            int num1 = nums[l];
            int num2 = nums[r];
            st.insert(float(num1+num2)/2.0);
            l++;
            r--;
        }
        return st.size();
    }
};