class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector <int> ans(n);
        int cur = 1;
        for(int i = 0; i <n; i++){
            if(ans[i]>0) continue;
            if(cur > 26) return "";
            for(int j = i; j <n; j++){
                if(lcp[i][j]>0){
                    ans[j] = cur;
                }
            }
            cur++;
        }
        for(int i = 0; i <n; i++){
            for(int j = 0; j <n; j++){
                int cur = 0;
                if(i+1 < n && j+1<n){
                    cur = lcp[i+1][j+1];
                }
                cur = (ans[i] == ans[j]) ? cur + 1:0;
                if(cur != lcp[i][j]) return "";
            }
        }
        string res;
        for(auto &x:ans) res += x - 1 + 'a';
        return res;
    }
};
// we need to form a string of size n
// lcp matrix of this string is given 
// in the matrix lcp[i][j] is equal to length of longest common prefix between substring 
//word[i,n-1] and word[j,n-1]
/*
lcp[i][i] will have just length of string left
lcp[0][1] can tell us if 



*/