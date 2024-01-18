class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map <int,int> freq;
        map <int,int> freq_cnt;
        int n = nums.size();
        int ans =1;
        for(int i = 0; i <n; i++){
            if(freq.count(nums[i])){
                freq_cnt[freq[nums[i]]]--;
                if(freq_cnt[freq[nums[i]]] == 0) freq_cnt.erase(freq[nums[i]]);
            }
            freq[nums[i]]++;
            freq_cnt[freq[nums[i]]]++;
            if(freq.size() == 1){
                ans = max(ans,i+1);
            }
            else if(freq_cnt.size() == 1){
                auto first = freq_cnt.begin();
                auto x = *first;
                if(x.first == 1){
                    ans = max(ans,i+1);
                }
            }
            else if(freq_cnt.size() == 2){
                auto first = freq_cnt.begin();
                auto second = freq_cnt.rbegin();
                auto x = *first;
                auto y = *second;
                if((x.first == 1 && x.second == 1 )|| ((x.first == y.first + 1) && (x.second == 1))){
                    ans = max(ans,i+1);
                }
                else if((y.first == 1 && y.second == 1 )|| ((y.first == x.first + 1) && (y.second == 1))){
                    ans = max(ans,i+1);
                }
                
            }
        }
        return ans;
    }
};