class Solution {
    const int mod = 1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0,n = arr.size();
        int odd_c = 0,even_c = 0;
        int cur_sum = 0;
        for(int i = 0; i <n; i++){
            cur_sum += arr[i];
            if(cur_sum&1){
                ans++;
                ans += even_c;
                ans%=mod;
                odd_c++;
            }
            else{
                ans+=odd_c;
                ans%=mod;
                even_c++;
            }
        }
        return ans%mod;
    }
};