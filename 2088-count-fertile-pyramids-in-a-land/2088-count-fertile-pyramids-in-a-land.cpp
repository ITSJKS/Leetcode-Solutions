class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector <vector <int>> prefix(n+1,vector <int>(m+1,0));
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                prefix[i+1][j+1] = prefix[i+1][j] + grid[i][j];
            }
        }
        int count = 0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                int x = i, y1 = j, y2 = j;
                int cnt = 1;
                while(x < n && y1 >= 0 && y2 <m){
                    int set_ones = prefix[x+1][y2+1] - prefix[x+1][y1];
                    if(set_ones == cnt){
                        cnt>1?count++:0;
                        cnt+=2;
                    }
                    else break;
                    x++,y1--,y2++;
                }   
            }
        }
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                int x = i, y1 = j, y2 = j;
                int cnt = 1;
                while(x >=0 && y1 >= 0 && y2 <m){
                    int set_ones = prefix[x+1][y2+1] - prefix[x+1][y1];
                    if(set_ones == cnt){
                        if(cnt>1)count++;
                        cnt+=2;
                    }
                    else break;
                    x--,y1--,y2++;
                }   
            }
        }
        return count;
    }
};

/*
Given
a farmer has a rectangular grid of land with m rows and n columns
each cell is either fertile or barren 
we need to find number of pyramidal and inverse pyramidal plots that can be found in grid
pyramidal and inverse pyramidal
I need to find number of pyramidal and number of inverse pyramidal 
so for every (r,c) we need to maximum height of the pyramid for which it is the apex
*/   