class Solution {
    int dr[4]= {1,-1,0,0};
    int dc[4]= {0,0,1,-1};
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image,sr,sc,val,color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc,int val, int color){
        int m = image.size();
        int n = image[0].size();
        if(sr<0 || sr >= m || sc <0 || sc >=n || image[sr][sc] == color || image[sr][sc] !=val){
            return;
        }
        image[sr][sc] = color;
        for(int i =0; i <4; i++){
            int sr1 = sr + dr[i];
            int sc1 = sc + dc[i];
            dfs(image,sr1,sc1,val,color);
        }      
        
    }

};