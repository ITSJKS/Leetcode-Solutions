class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
           int n=matrix.size(),m=matrix[0].size();
        int l=1,r=min(n,m);
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x,y,z;
                x=(i>=1)?dp[i-1][j]:0;
                y=(j>=1)?dp[i][j-1]:0;
                z=(i>=1 && j>=1)?dp[i-1][j-1]:0;
                dp[i][j]=(matrix[i][j]-'0')+x+y-z;
            }
        }
        auto ok=[&](int mid)->bool
        {
            for(int i=mid-1;i<n;i++)
            {
                for(int j=mid-1;j<m;j++)
                {
                    int pi=i-(mid-1),pj=j-(mid-1);
                    
                    int x,y,z;
                    x=(pi>=1)?dp[pi-1][j]:0;
                    y=(pj>=1)?dp[i][pj-1]:0;
                    z=(pi>=1 && pj>=1)?dp[pi-1][pj-1]:0;
                    int sum=dp[i][j]-x-y+z;
                    if(sum==(mid*mid))
                    {
                        return 1;
                    }
                }
            }
            return 0;
        };
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(ok(mid))
            {
                ans=mid*mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};