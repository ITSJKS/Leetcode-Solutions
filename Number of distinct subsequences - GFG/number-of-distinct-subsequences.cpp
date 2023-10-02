//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int mod = 1e9 + 7;
    int distinctSubsequences(string s) {
        int n = s.size();
        vector <int> dp(26,0);
        for(int k = 0; k <n;k++){
            int cur = s[k] - 'a';
            dp[cur] = ((accumulate(dp.begin(),dp.end(),0ll))+1+mod)%mod;
        }
        return (accumulate(dp.begin(),dp.end(),0ll)+1)%mod;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends