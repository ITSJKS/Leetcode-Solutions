class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& nums1, vector<int>& nums2, int k) {
         vector <pair <int,int>> v;
        for(int i = 0; i <n; i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue <int,vector <int>, greater<int>> pq;
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i <n; i++){
            pq.push(v[i].second);
            sum += v[i].second;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans,sum*v[i].first);
        }
        return ans%mod;
    }
};