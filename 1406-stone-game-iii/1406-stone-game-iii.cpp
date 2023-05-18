class Solution {
public:
    int dp[50001][2];
    int solve(int ind, bool turn, vector <int> &sV){
        if(ind == sV.size()) return 0;
        // if alice turn , she will want to maximize her score so i want maximum differnce between her score and her friend
        if(dp[ind][turn] != -1) return dp[ind][turn];
        if(turn){
            int maxi =  INT_MIN;
            int cur = 0;
            for(int j = ind; j<min(ind + 3,(int)sV.size()); j++){
                cur += sV[j];
                maxi = max(maxi,cur + solve(j+1,!turn,sV));
            }
            return maxi;
        }
        else{
            int mini = INT_MAX;
            int cur = 0;
            for(int j = ind; j<min(ind + 3,(int)sV.size()); j++){
                cur += sV[j];
                mini = min(mini,solve(j+1,!turn,sV));
            }
            return dp[ind][turn] = mini;
        }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        int score = solve(0,1,stoneValue);
        int total = accumulate(stoneValue.begin(),stoneValue.end(),0);
        int bob = total - score;
        // cout<<score<<endl;
        if(score == bob) return "Tie";
        if(score > bob) return "Alice";
        return "Bob";
    }
};