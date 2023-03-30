class Solution {
public:
    long long maxPower(vector<int>& nums, int r, int k) {
        int n= nums.size();
        vector <long long> prefix(n,0);
        vector <long long> prefix2(n,0);
        for(int i = 0; i < n; i++){
            prefix[i] = nums[i];
            prefix2[i] = nums[i];
        }
        for(int i = 0; i < n; i++){
            if(i+r+1 < n) prefix[i+r+1] -= nums[i];
        }
        for(int i = 1; i < n; i++){
            prefix[i]+= prefix[i-1];
        }
        for(int i = n-1; i>=0; i--){
            if(i - r >0) prefix2[i-r-1] -= nums[i];
        }
        for(int i = n-2; i >=0; i--){
            prefix2[i] += prefix2[i+1];
        }
        for(int i = 0; i < n; i++){
            prefix[i]+=prefix2[i] - nums[i];
        }
        auto check  = [&](long long mid){
            vector <long long> temp = prefix;
            vector <long long> change(n+1,0);
            int K = k;
            long long c = 0;
            for(int i = 0; i < n; i++){
                if(change[i]) c += change[i];
                if(temp[i]+c < mid){
                    long long diff = mid - (temp[i]+c);
                    if(diff > K) return false;
                    K -= diff;
                    if(i+2*r+1 < n)
                        change[i+2*r+1] -= diff;
                    c += diff;
                }
            }
            return true;
        };
        long long low = *min_element(prefix.begin(),prefix.end())-1;
        long long right = 1e9 + 1e10 + 1;
        while(right-low>1){
            long long mid = low + (right-low)/2;
            if(check(mid)) low = mid;
            else right = mid;
        }
        return low;
    }
};

// we can create a prefix array of initial powers , then we can greedily give powers so that the minimum powered one can be increased
// we can apply binary search here , we will check for a minimum power , if we can make the power of the stations upto that point we will get the power