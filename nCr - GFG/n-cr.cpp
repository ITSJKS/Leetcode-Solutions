//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    int mod = 1e9 + 7;
    int nCr(int n, int r){
        if(r>n) return 0;
        // code here
        vector <long long> fact(1001);
        fact[0] = 1;
        for(int i = 1; i <=1000; i++){
            fact[i] = (fact[i-1]*1ll*i)%mod;
        }
        long long ans = (fact[n]*1ll*binpow(fact[n-r]*1ll*fact[r],mod-2,mod))%mod;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends