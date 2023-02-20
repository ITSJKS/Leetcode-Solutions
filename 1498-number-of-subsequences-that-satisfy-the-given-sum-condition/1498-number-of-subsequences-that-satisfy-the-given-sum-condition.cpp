int mod  = 1e9 + 7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int n = nums.size();
        int h = nums.size()-1;
        int ans = 0;
        vector<int>pow2(n+1,1);
        for(int i=1;i<=n;i++)
        {
            pow2[i]=(2*pow2[i-1])%mod;
        }
        while(l<=h){
            int x = nums[l] + nums[h];
            if(x <=target){
                ans = (ans+pow2[h-l])%mod;
                l++;
            }
            if(x>target) h--;
            
        }
        return ans;
    }
};