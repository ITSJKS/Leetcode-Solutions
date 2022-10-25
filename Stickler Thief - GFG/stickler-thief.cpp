//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector <int> dp(n+1,-1);
        return find_ans(n-1,arr,dp);
    }
    int find_ans(int idx,int *arr,vector <int> &dp){
        if(idx == 0) return arr[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick  = arr[idx] + find_ans(idx-2,arr,dp);
        int notpick = 0 + find_ans(idx-1,arr,dp);
        return dp[idx] = max(pick,notpick);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends