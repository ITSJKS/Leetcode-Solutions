class Solution {
public:
    string primes = "2357";
    string nonPrimes = "014689";
    int mod = 1e9 + 7;
    int dp[1001][1001][2];
    int solve(int ind, int k,int start,string &s, int len){
        if(ind == s.size()) return k==0;
        if(k < 0) return 0;
        if(ind > s.size() || k== 0 || start && primes.find(s[ind])==string::npos) return 0;
        if(dp[ind][k][start]!=-1) return dp[ind][k][start];
        int count = 0;
        if(primes.find(s[ind])!=string::npos){
            if(start){
                count = solve(ind+len-1,k,!start,s,len);
            }
            else{
                count = solve(ind+1,k,start,s,len);
            }
        }
        else{
                count = solve(ind+1,k,start,s,len);
                count = (count + solve(ind+1,k-1,!start,s,len))%mod;
        }
        return dp[ind][k][start] = count;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        memset(dp,-1,sizeof dp);
        return solve(0,k,true,s,minLength);
    }
};
/*
Given a string s that consists of the digits '1' to '9' and two integers k and minLength

a partition of s is called beautiful if :

s is partitioned into k non intersecting substrings 
each substring has a length at least minLength and each substring start with a prime digit and ends with a non-prime digit



*/