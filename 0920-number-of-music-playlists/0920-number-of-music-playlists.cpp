class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101];
    int solve(int goal, int cur_n,int k,int n){
        if(goal == 0 && cur_n == 0) return 1;
        if(goal  == 0 || cur_n == 0) return 0;
        if(dp[goal][cur_n]!=-1) return dp[goal][cur_n];
        long long ans = 0;
        // if i add a new song
        // number of ways to get goal - 1 song using cur_n - 1 unique song
        // so when adding the current song we have n - (cur_n - 1) options to add to our current playlist
        ans = (ans + ((n -(cur_n-1))*1ll*solve(goal-1,cur_n-1,k,n))%mod)%mod;
        
        // how to add the alredy played song to our current playlist
        // when we don't add new song then we will get number of ways to get number of ways to get goal - 1 song with cur_n unique song, if that cur_n is greater than k , then we can reuse the old songs
        // number of options for new song == cur_n - k as that many songs were renewed 
        if(cur_n > k)
        ans = (ans + (cur_n-k)*1ll*solve(goal-1,cur_n,k,n))%mod;
        return dp[goal][cur_n] = ans;
    
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof dp);
        return solve(goal,n,k,n);
    }
};
// every song is played at least once
// a song can only be played again if only if k other songs has been played
// n different songs
// we wanna listen to goal songs
// repeat only after k other songs has been played

// 1 2
// 1 2 1
// 2 1 1
    
// 1 2 3
// 1 2 3
