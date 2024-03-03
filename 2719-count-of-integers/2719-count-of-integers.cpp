class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int mod = 1e9 +7;
        int dp[23][2][201];
        if(max_sum >= 200) max_sum = 200;
        function<int(int,bool,int,string&)> solve = [&](int ind, bool flag, int sum,string &num) {
            if(ind == num.size()) return int(sum>=min_sum && sum <= max_sum);
            if(dp[ind][flag][sum]!=-1) return dp[ind][flag][sum];
            int ub = flag?(num[ind]-'0'):9;
            long long count = 0;
            for(int i  =0; i <=ub; i++){
                int new_flag = flag&(i == num[ind]-'0');
                count = (count + solve(ind+1,new_flag,sum+i,num))%mod;
            }
            return dp[ind][flag][sum] = (int)count;
        };
        int cnt = 0;
        for(auto &x:num1) cnt+=(x-'0');
        int cur = 0;
        if(cnt >= min_sum && cnt <= max_sum) cur = 1;
        memset(dp,-1,sizeof dp);
        long long res = solve(0,1,0,num2);
        memset(dp,-1,sizeof dp);
        res = (res-solve(0,1,0,num1)+cur+mod)%mod;
        return res;
    }
};

/*
we are given two numeric string num1 and num2 and two integers max_sum and 
minsum we need to find all those good integers whose digit sum is between min_sum and max_sum and those number is betwen num1 and num2

*/

/*
Approach 
we can try to find all those number less than num1 whose digit sum is between min_sum and max_sum
we can apply digit dp for that
we can keep a current sum and in the end if that sum is between min and max then I will return the answer, for digit dp we try to form number as we go 




*/