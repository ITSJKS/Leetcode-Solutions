class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector <int> v(110,0);
        for(auto x:logs){
            v[x[0]- 1950] += 1;
            v[x[1] - 1950] -= 1;
        }
        int cur= 0,maxi = 0, year = 0;
        for(int i = 0; i <=100; i++){
            cur += v[i];
            if(cur > maxi){
                maxi = cur;
                year = i + 1950;
            }
        }
        return year;
    }
};