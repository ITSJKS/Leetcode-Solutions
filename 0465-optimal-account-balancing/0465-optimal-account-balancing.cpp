class Solution {
public:
   
    int minTransfers(vector<vector<int>>& t) {
        vector <int> v(12,0);
        for(auto &x:t){
            int f = x[0] , t = x[1], amount = x[2];
            v[f]-=amount;
            v[t]+=amount;
        }
        vector <int> ans;
        for(auto &x:v) if(x) ans.push_back(x);
        int n = ans.size();
        int m = 1<<n;
        vector <int> dp(m,0);
        for(int i = 1; i <m; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(i&(1<<j)){
                    dp[i] = max(dp[i],dp[i^(1<<j)]); // here I am trying to find what will be the best solution we can get by considering the submask of the current mask
                    
                    sum += ans[j];
                }
            }
            if(sum == 0) dp[i]++;
        }
        return n - dp.back();
    }
};

// Maybe I can try to apply dp here
// suppose in the end I have debt array as 
// -15 -10 -5 3 12 15
// we have to find minimum number of transaction to settle the debt
// last person decide to pay
// we can try to form groups in the new transacton array such that sum of element in each group is zero , in that way we can make sure that total transaction will be n - m where m is group as each group decrease our transation count by 1