class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map <int,int> mp;
        for(int i = 0; i <n; i++){
            int temp = 0;
            for(int j = 0; j <m; j++){
                if(grid[i][j]) temp |= (1<<j);
            }
            if(mp.count(temp) ==0) mp[temp] = i;
            if(temp == 0) return {i};
        }
        for(int i = 0; i <(1<<m); i++){
            if(mp.count(i) == 0) continue;
            for(int j = i+1; j < (1<<m); j++){
                if((i&j) == 0 && (mp.count(i) && mp.count(j))){
                    int a = mp[i];
                    int b = mp[j];
                    if(a > b) swap(a,b);
                    return {a,b};
                }
            }
        }
        return {};
    }
};
