class Solution {
public:
    int N = 2e5 + 2;
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector <int> prefix(N+1,0);
        for(auto x:fruits){
            prefix[x[0]+1] = x[1];
        }
        for(int i = 1; i <=N; i++){
            prefix[i]+=prefix[i-1];
        }
        startPos++;
        int maxi = 0;
        int l ,r ;
        for(r = startPos; r <N && r<startPos  + k; r++){
            l  = min(startPos,startPos - k + 2*(r-startPos));
            l = max(1,l);
            maxi = max(maxi,prefix[r]-prefix[l-1]);
        }
        for(l = startPos; l >0 && l>=startPos-k; l--){
            int step = startPos - l;
             r = max(startPos,startPos + k - 2*step);
             r = min(N-1,r);
             maxi = max(maxi,prefix[r]-prefix[l-1]);
        }
        return maxi;
    }
};