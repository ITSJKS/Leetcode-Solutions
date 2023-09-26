class Solution {
public:
    int dp[101][101];
    int solve(int ind ,vector <int> &houses, int k){
        int n = houses.size();
        if(ind >= n) return 0;
        int ans = 1e9;
        if(dp[ind][k]!=-1) return dp[ind][k];
        if(k == 1){
            int mid = ind + (n-ind)/2;
            int sum = 0;
            for(int j = ind; j <n; j++){
                sum += abs(houses[mid] - houses[j]);
            }
            return sum;
        }
        for(int j = ind; j <n; j++){
            int mid = ind + (j-ind+1)/2;
            int sum = 0;
            for(int k = ind; k <=j; k++){
                sum += abs(houses[mid]-houses[k]);
            }
            ans = min(ans,sum + solve(j+1,houses,k-1));
        }
        return dp[ind][k] = ans;
    }
    int minDistance(vector<int>& houses, int k) {
        memset(dp,-1,sizeof dp);
        sort(houses.begin(),houses.end());
        return solve(0,houses,k);
    }
};

/*
we are given the array of houses where houses[i]  is the location of the ith house along a street and an integer k , allocate k mailboxes in the street.

if k  is one we can just put the mail at middle of all the houses

we can do this
for every few houses we can try to put mailbox in the middle of those houses and find how much distance we will have to travel if we 
*/