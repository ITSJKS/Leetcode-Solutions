class Solution {
public:
    int dp[10][10][10][21][2];
    int solve(int i, string h, int even , int odd,int rem, bool isless,int k){
        if(i == h.size()){
            // cout<<even<<" "<<odd<<" "<<rem<<endl;
            if(even == odd && (rem%k) == 0) return 1;
            return 0;
        }
        if(dp[i][even][odd][rem][isless]!=-1) return dp[i][even][odd][rem][isless];
        int cnt = 0;
        int left = h.size() - i - 1;
        // cout<<i<<" "<<left<<endl;
        int ub = isless?9:(h[i]-'0');
        for(int j =0 ; j<=ub; j++){
            int ne = even + (j%2 == 0);
            if(j == 0 && (even + odd == 0)) ne = 0;
            int no = odd + (j%2);
            int nrem = ((j*(int)pow(10,left)) + rem)%k;
            // cout<<nrem<<endl;
            int nflag = (isless == 0) && (j == ub)?0:1;
            cnt += solve(i+1,h,ne,no,nrem,nflag,k);
        }
        return dp[i][even][odd][rem][isless] = cnt;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp,-1,sizeof dp);
        string h = to_string(high);
        string l = to_string(low-1);
        int cnt_h = solve(0,h,0,0,0,0,k);
        memset(dp,-1,sizeof dp);
        int cnt_l = solve(0,l,0,0,0,0,k);
        int ans = cnt_h - cnt_l;
        return ans;
    }
};

/*

I can find number of value in the range[0, high]
I can find number of value in the range [0,low]
I can find if low is valid or not
*/