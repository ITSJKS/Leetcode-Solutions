class Solution {
public:
    int coinChange(vector<int>& num, int x) {
        int n = num.size();
    vector <int> prev(x+1),cur(x+1);
    for(int w = 1; w<=x; w++){
        if(w%num[0] == 0) prev[w] = w/num[0];
        else prev[w] = 1e8;
    }
    for(int idx = 1; idx <n; idx++){
        for(int wt = 0; wt <= x; wt++ ){
            int notTake = prev[wt];
            int take = 1e8;
            if(num[idx]<=wt) take = 1 + prev[wt-num[idx]];
            prev[wt] = min(take,notTake);
        }
        cur = prev;
    }
      int res = prev[x];
      if(res>=1e8) return -1;
      return res;
    }
};