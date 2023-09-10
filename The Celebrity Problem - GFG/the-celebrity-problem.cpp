//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack <int> st;
        for(int i = 0; i <n; i++){
            st.push(i);
        }
        while(st.size()>1){
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.pop();
            if(M[top1][top2]) st.push(top2);
            else st.push(top1);
        }
        int top = st.top();
        int count =0 , count2 = 0;
        for(int i = 0; i <n; i++){
            if(i == top) continue;
            if(M[i][top] == 0 || M[top][i]) return -1;
        }
        return top;
        // if(count == n-1 && count2 == 0) return true;
        // return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends