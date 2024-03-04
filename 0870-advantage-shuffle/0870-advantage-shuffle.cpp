class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector <pair<int,int>> v2;
        int n = nums1.size();
        for(int i = 0; i <n; i++){
            v2.push_back({nums2[i],i});
        }
        sort(nums1.begin(),nums1.end());
        sort(v2.begin(),v2.end());
        int count = 0;
        vector <int> v;
        vector <int> ans(n,-1);
        for(int r = 0,i = 0; r <n && i <n; r++){
            if(nums1[r] > v2[i].first){
                ans[v2[i].second] = nums1[r];
                i++;
            }
            else v.push_back(nums1[r]);
        }
        int j = 0;
        for(auto &x:v){
            while(j < n && ans[j] != -1) j++;
            ans[j] = x;
        }
        return ans;
    }
};