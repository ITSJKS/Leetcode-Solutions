class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set <vector <int>> st;
        for(int i = 0; i <n; i++){
            vector <int> v;
            int cnt = 0;
            for(int j = i; j <n; j++){
                v.push_back(nums[j]);
                cnt += nums[j]%p == 0;
                if(cnt > k) break;
                st.insert(v);
            }
        }
        return st.size();
    }
};