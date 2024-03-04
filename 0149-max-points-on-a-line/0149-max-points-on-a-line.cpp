class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int ans = 0;
        for(int i = 0; i <n-1; i++){
            map<pair<int ,int> ,int > mp;
            int maxi = 0;
            for(int j = i+1; j < n; j++){
                int x1 = points[i][0],y1 = points[i][1];
                int x2 = points[j][0] , y2 = points[j][1];
                int dy = y2-y1;
                int dx = x2-x1;
                int gcd = __gcd(dy,dx);
                if(gcd){
                    dy/=gcd;
                    dx/=gcd;
                }
                // cout<<i<<" "<<j<<" ";
                // cout<<dy<<" "<<dx<<endl;
                if(dy >= 0 && dx >= 0){
                      mp[{dy,dx}]++;
                      maxi = max(maxi,mp[{dy,dx}]);
                }
                else if(dy >=0 || dx>=0){
                    mp[{abs(dy),-(abs(dx))}]++;
                    maxi = max(maxi,mp[{abs(dy),-(abs(dx))}]);
                }
                else if(dy < 0 && dx < 0){
                      mp[{-dy,-dx}]++;
                      maxi = max(maxi,mp[{dy,dx}]);
                }
            }
             ans = max(maxi+1,ans);
        }
        return ans;
        
    }
};