class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector <int> b;
        int ans = 0;
        for(int i = 0; i <pow(2,n); i++){
            int g = i ^(i>>1);
            if(g == start) ans = i;
            b.push_back(g);
        }
        vector <int> res;
        for(int i = ans; i < (1<<n); i++){
            res.push_back(b[i]);
        }
        for(int i = 0; i <ans; i++){
            res.push_back(b[i]);
        }
        return res;
    }
};