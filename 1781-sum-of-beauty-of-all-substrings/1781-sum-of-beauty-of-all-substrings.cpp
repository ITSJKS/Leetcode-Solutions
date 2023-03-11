class Solution {
public:
    int find_beauty(int i, int j,vector <vector <int>> &freq){
        vector <int> b(26);
        for(int k = 0; k < 26; k++){
            b[k] = freq[j][k];
            int c = 0;
            if(i>0){
                c = freq[i-1][k];
                b[k] -= c;
            }
        }
        int mini = INT_MAX;
        int maxi = 0;
        for(auto x:b){
            if(x!=0){
               maxi = max(maxi,x);
               mini = min(mini,x); 
            }
        }
        return maxi - mini;
    }
    int beautySum(string s) {
        int n = s.size();
        vector <vector <int>> freq(n,vector <int>(26,0));
        for(int i = 0; i <n; i++){
            freq[i][s[i]-'a']++;
        }
        for(int i = 1; i <n; i++){
            for(int j = 0; j <26; j++){
                freq[i][j] += freq[i-1][j];
            }
        }
        int count = 0;
        for(int i = 0; i <n; i++){
            for(int j = i+1; j < n; j++){
                count += find_beauty(i,j,freq);
            }
        }
        return count;
    }
};