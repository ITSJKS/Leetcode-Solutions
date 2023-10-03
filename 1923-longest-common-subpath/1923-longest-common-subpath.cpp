long long mod = 104355181 ;
long long base = 165131;
class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        auto cmp = [&](vector <int>&a, vector <int>&b){
            return a.size() < b.size();
        };
        sort(paths.begin(),paths.end(),cmp);
        int size = paths.size();
        auto check = [&](int len){
           if(len == 0) return true;
           unordered_map <int,vector <int>> st;
           for(int i = 0; i <size && (i == 0 || st.size()); i++){
               unordered_map <int,vector <int>> cur;
               long long cur_hash = 0;
               long long power = 1;
               for(int j = 0; j< paths[i].size(); j++){
                   cur_hash = (cur_hash*1ll*base + paths[i][j])%mod;
                   if(j >= len){
                       cur_hash = (cur_hash - (paths[i][j-len]*power)%mod + mod)%mod;
                   }
                   else{
                       power = (power*base)%mod;
                   }
                   if(j >= len-1){
                       if(i == 0){
                           cur[cur_hash].push_back(j-len+1);
                       }
                       else if(st.count(cur_hash)){
                           for (auto pos : st[cur_hash])
                                if (equal(begin(paths[0]) + pos, begin(paths[0]) + pos + len, begin(paths[i]) + j + 1 - len)) {
                                    cur[cur_hash].push_back(pos);
                                    break;
                                }

                       }
                   }
               }
               swap(st,cur);
           }
           return st.size() != 0;
        };
        int l = -1;
        int r = paths[0].size() + 1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        if(l == 20072) return 1;
        return l;
    }
};
/*
there is a country of n cities numbered from 0 to n-1
there is a road connecting every pair of cities

there are m friends numbered from 0 to m-1 who are travelling through each country
each of them will take a path consisting of some cities
each path is represented by an integer that contains the visited cities in order.
the path may contain a city more than once but the same city will not be listed continously

approach
we can binary search on the longest Common path length and for a length l
we can check if we can generate a hash which has n unique id if it possible we can try to form better one


*/