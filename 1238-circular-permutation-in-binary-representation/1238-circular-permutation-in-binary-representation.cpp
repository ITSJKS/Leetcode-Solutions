class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector <int> b;
        for(int i = 0; i <pow(2,n); i++){
            int g = start^i ^(i>>1);
            b.push_back(g);
        }
        return b;
    }
};