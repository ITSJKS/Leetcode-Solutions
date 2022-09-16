class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        
        int i = 0, j = n-1, sum = 0;
        
        for(i=0; i<k; ++i)
        {
            sum+= cp[i];
        }
        i--;

        int ans = sum;
        
        while(i>=0)
        {
            sum-= cp[i--];
            sum+= cp[j--];
            ans = max(ans, sum);
        }
        
        return ans;
        
    }
};