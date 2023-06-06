class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        vector <int> prefix(n,1);
        int cur_len = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i-1]){
                cur_len++;
            }
            else cur_len = 1;
            prefix[i] = cur_len;
        }
        vector <int> suffix(n,1);
        cur_len = 1;
        for(int i = n-2; i>=0; i--){
            if(arr[i] > arr[i+1]) cur_len++;
            else cur_len = 1;
            suffix[i] = cur_len;
        }
        int ans = 0;
        for(int i = 1; i <n-1; i++){
            if(prefix[i] > 1 && suffix[i] > 1) ans = max(ans,prefix[i]+suffix[i] -1);
        }
        return ans;
    }
};

// length of longest subarray which is a mountain 
// keep longest mountain in our current window at idx, if our mountain get discarded at any point , we have to restart again as the current mountain length will be 0 only