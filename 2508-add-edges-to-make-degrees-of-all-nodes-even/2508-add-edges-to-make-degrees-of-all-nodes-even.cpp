class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        map <pair<int,int>,int> mp;
        vector  <int> degree(n+1,0);
        for(auto &x:edges){
            int u = x[0] , v = x[1];
            degree[u]++;
            degree[v]++;
            mp[{u,v}] = 1;
        }
        vector <int> odd;
        for(int i = 1; i <=n; i++){
            if(degree[i]%2 == 1) odd.push_back(i);
        }
        int s = odd.size();
        // cout<<s<<endl;
        if(s == 0) return true;
        if(s&1 || (s!=2 && s!=4)) return false;
        if(s == 2){
            int u = odd[0] , v = odd[1];
            // cout<<mp.count({u,v});
            if(mp.count({u,v}) || mp.count({v,u})){
                for(int i = 1; i <=n; i++){
                    if(u == i || v == i) continue;
                    if(mp.count({u,i}) || mp.count({i,u})) continue;
                    if(mp.count({v,i}) || mp.count({v,u})) continue;
                    return true;
                }
                return false;
            }
            else{
                return true;
            }
        }
        else{
            // when 4 nodes are odd , we have to connect themselves among themselves
            auto check = [&](int a, int b){
                if(mp.count({a,b}) || mp.count({b,a})) return false;
                return true;
            };
            int a = odd[0] , b = odd[1] ,  c = odd[2] , d = odd[3];
            if(check(a,b) && check(c,d) || check(a,c) && check(b,d) || check(a,d) && check(b,c)) return true;
            return false;
        }
    }
};