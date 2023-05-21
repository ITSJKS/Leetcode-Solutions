#define ll long long 
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        ll i = k;
        ll j = k;
        ll mini = nums[k];
        ll score = nums[k];
        int n = nums.size();
        while(i > 0 || j < n-1){
            if(i == 0){
                j++;
            }
            else if(j == n-1){
                i--;
            }
            else{
                ll a = nums[i-1];
                ll b = nums[j+1];
                if(a < b) j++;
                else i--;
            }
            mini = min(mini,(ll)min(nums[i],nums[j]));
            ll len  = j - i + 1;
            score = max(score,mini*len);
        }
        return score;
    }
};