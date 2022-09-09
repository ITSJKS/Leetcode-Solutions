class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector <int> &v1,vector <int> &v2){if(v1[0] == v2[0]) return v1[1]>v2[1];return v1[0]<v2[0];});
        int mini = INT_MIN;
        int n = p.size();
        int ans = 0;
        for(int i = n-1; i>=0; i--){
            if(p[i][1]<mini) ans++;
            mini = max(mini,p[i][1]);
        }
        return ans;
        
        
    }
};