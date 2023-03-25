class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector <int> fact = {1,1,2,6,24,120,720,5040};
        set <string> visited;
        int n = tiles.size();
        int count = 0;
        for(int i = 1; i <(1<<n); i++){
            string s;
            for(int j = 0; j < n; j++){
                if(i&(1<<j)){
                    s.push_back(tiles[j]);
                }
            }
            sort(s.begin(),s.end());
            if(visited.count(s)) continue;
            visited.insert(s);
            map <char,int> mp;
            for(auto x:s){
                mp[x]++;
            }
            long long fact1 = fact[s.size()];
            long long fact2 = 1;
            for(auto x:mp){
                fact2*=fact[x.second];
            }
            count += (fact1)/fact2;
        }
        return count;
    }
};