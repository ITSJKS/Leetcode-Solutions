class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int size = n*m;
        int ans = 1e9;
        vector <int> dir = {0,1,0,-1,0};
        auto check = [&](int mask){
            vector <vector <int>> res = mat;
            for(int j = 0; j <n; j++){
                for(int k = 0; k <m; k++){
                    int cur_bit = k + (j)*m;
                    if(mask&(1<<cur_bit)){
                        res[j][k] ^= 1;
                        for(int d = 0; d <4; d++){
                            int dx = j + dir[d];
                            int dy = k + dir[d+1];
                            if(dx >=0 && dx < n && dy >= 0 && dy <m){
                                res[dx][dy] ^= 1;
                            }
                        }
                    }
                }
            }
            for(int j = 0; j <n; j++){
                for(int k = 0; k <m; k++){
                    if(res[j][k]) return false;
                }
            }
            return true;
        };
        for(int i = 0; i <(1<<size); i++){
            if(check(i)) ans = min(ans,__builtin_popcount(i));
            if(ans <= 1) return ans;
        }
        return ans==1e9?-1:ans;
    }
};

/*
Let's do a brute force way
matrix will look like this

0 1 2
3 4 5
6 7 8

we can do a subset logic where if the number of 



*/