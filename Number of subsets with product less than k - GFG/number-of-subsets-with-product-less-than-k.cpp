//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numOfSubsets(int arr[], int n, int k) {
        // code here
        int mid = n/2;
        vector <int> v;
        for(int i = 0; i <(1<<mid); i++){
            int product = 1;
            bool check = true;
            for(int j = 0; j <mid; j++){
                if(i&(1<<j)) product*=arr[j];
                if(product >k){
                    check = false;
                    break;
                }
            }
            if(check) v.push_back(product);
            
        }
        sort(v.begin(),v.end());
        // debug(v);
        vector <int> rem;
        for(int i = mid; i <n; i++){
            rem.push_back(arr[i]);
        }
        int s = rem.size();
        int count = v.size()-1;
        for(int i = 1; i <(1<<s); i++){
            int product = 1;
            bool check = true;
            for(int j = 0; j <s; j++){
                if(i&(1<<j)) product*=rem[j];
                if(product >k){
                    check = false;
                    break;
                }
            }
            if(check){
                // cout<<k/product<<" ";
                auto it = upper_bound(v.begin(),v.end(),k/product);
                it--;
                count += (it-v.begin()+1);
            }
        }
        return count;
        
    }
    // we need to divide the array into two part and try to combine both part to form an answer
    // 0 2 4 8 
    // 5 3 15 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends