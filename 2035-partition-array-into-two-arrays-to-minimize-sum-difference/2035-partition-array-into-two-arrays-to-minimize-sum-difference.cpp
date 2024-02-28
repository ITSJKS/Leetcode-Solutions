class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector <int> left(nums.begin(),nums.begin()+n);
        vector <int> right(nums.begin()+n,nums.begin()+2*n);
        // generate masks for left and store it in a vector containing
        vector <vector <int>> masks(n+1);
        for(int i = 0; i <(1<<n); i++){
            int set_cnt = __builtin_popcount(i);
            int score = 0;
            for(int j = 0; j <n; j++){
                if(i&(1<<j)) score += left[j];
                else score -= left[j];
            }
            masks[set_cnt].push_back(score);
        }
        for(auto &v:masks) sort(v.begin(),v.end());
        
        // now we will generate masks for our second array which is right part, and check in n - set_bit for closest value
        int ans = INT_MAX;
        for(int j = 0; j <(1<<n); j++){
            int set_cnt = __builtin_popcount(j);
            int score = 0;
            for(int k = 0; k < n; k++){
                if(j&(1<<k)) score += right[k];
                else score -= right[k];
            }
            int search_key = n - set_cnt;
            auto it = lower_bound(masks[search_key].begin(),masks[search_key].end(),-score);
            if(it != masks[search_key].begin()){
                ans = min(ans,abs(score + *(prev(it))));
            }
            if(it!=masks[search_key].end()) ans = min(ans,abs(score + *it));
            
        }
        return ans;
    }
};