class Solution {
public:
    vector <int> convert(vector <vector <int>> &matrix){
        vector <int> ans;
        for(auto x:matrix){
            int num = 0;
            int p = 1;
            reverse(x.begin(),x.end());
            for(auto y:x){
                if(y) num += p;
                p*=2;
            }
            ans.push_back(num);
        }
        return ans;
    }
    int maximumRows(vector<vector<int>>& matrix, int ns) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <int> new_m = convert(matrix);
        int maxi = 0;
        for(int i =1 ; i <=(1<<m); i++){
            if(__builtin_popcount(i) == ns){
                int count = 0;
                for(auto y:new_m){
                    // cout<<y<<" ";
                    if((i&y) == y) count++;
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};

// generate all subset from 1 to 1<<n  when popcount of n == numselect now go around each row and check and keep max count;