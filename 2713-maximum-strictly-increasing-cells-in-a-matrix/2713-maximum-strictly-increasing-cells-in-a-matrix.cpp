class Solution {
public:
     int bs(vector<pair<int,int>> &vec,int ele){
        int l=0,r=vec.size()-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(vec[mid].first>ele){ans=mid;r=mid-1;}
            else{l=mid+1;}
        }
        return ans;
    }
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp, vector <vector <pair<int,int>>> &rows, vector <vector <pair<int,int>>> &cols)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int path = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        vector <pair<int,int>> t;
        int num = matrix[i][j];
        pair<int,int> p {num,INT_MIN};
        auto r = bs(rows[i],num);
        auto c = bs(cols[j],num);
        // auto r = upper_bound(rows[i].begin(),rows[i].end(),p) - rows[i].begin();
        // auto c = upper_bound(cols[j].begin(),cols[j].end(),p) - cols[j].begin();
        if(r!=-1){
            int cl=r;
            
            while(cl<rows[i].size()&&matrix[i][rows[i][cl].second]==matrix[i][rows[i][r].second]){t.push_back({i,rows[i][cl].second});cl++;}
        }
        if(c!=-1){
            int rw=c;
            while(rw<cols[j].size()&&matrix[cols[j][rw].second][j]==matrix[cols[j][c].second][j]){t.push_back({cols[j][rw].second,j});rw++;}
        }
        for(auto &x:t){
            int i1 = x.first;
            int j1 = x.second;
            path = max(path,1 + f(i1,j1,matrix,dp,rows,cols));
        }
        return dp[i][j] = path;
    }
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector <pair<int,int>>> rows(n);
        vector <vector <pair<int,int>>> cols(m);
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                rows[i].push_back({mat[i][j],j});
                cols[j].push_back({mat[i][j],i});
            }
        }
        for(int i = 0; i <n; i++) sort(rows[i].begin(),rows[i].end());
        for(int i = 0; i <m; i++){
            sort(cols[i].begin(),cols[i].end());
        }
        vector <vector <int>> dp(n,vector <int>(m,-1));
        int ans = 0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j <m; j++){
                ans = max(ans,f(i,j,mat,dp,rows,cols));
            }
        }
        return ans;    
    }
};