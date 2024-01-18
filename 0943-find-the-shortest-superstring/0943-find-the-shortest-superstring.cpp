class Solution {
public:
     int cost (string &A, string &B) {
        for(int i = 0; i < A.size(); i++) {
            string _A = A.substr(i, A.size());
            if (_A.size() <= B.size() && B.substr(0, _A.size()) == _A) {
                return B.size() - _A.size();
            }
        }
        return B.size();
    }
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector <vector <int>> costs(n,vector <int>(n));
        for(int i = 0; i <n; i++){
            for(int j = i+1; j <n; j++){
                string s = words[i],t = words[j];
                costs[i][j] = cost(s,t);
                costs[j][i] = cost(t,s);
            }
        }
        int mini = 1e9;
        int last = -1;
        int N  = (1<<n) - 1;
        vector <vector <int>> dp(N+1,vector <int>(n));
        vector <vector <int>> paths(N+1,vector <int>(n));
        for(int i = 1; i <=N; i++){
            for(int j = 0; j <n; j++) dp[i][j] = 1e9;
            for(int cur = 0; cur<n; cur++){
                if(i&(1<<cur)){
                    int prev_mask = i ^ (1<<cur);
                    if(prev_mask == 0){
                        dp[i][cur] = words[cur].size();
                    }
                    else{
                        for(int prev = 0; prev < n; prev++){
                            if(dp[prev_mask][prev] < 1e9 && dp[prev_mask][prev] + costs[prev][cur] < dp[i][cur]){
                                dp[i][cur] = dp[prev_mask][prev] + costs[prev][cur];
                                paths[i][cur] = prev;
                            }
                        }
                    }
                }
            if(i == N && mini > dp[i][cur]){
                mini = dp[i][cur];
                last = cur;
            }
            }
        }
        N  = (1<<n) - 1;
        vector <int> path;
        while(N!=0){
            path.push_back(last);
            int prev = N;
            N  = N ^ (1<<last);
            last = paths[prev][last];
        }
        last = path.back();
        string ans = words[path.back()];
        path.pop_back();
        while(path.size()){
            int next = path.back();
            path.pop_back();
            ans += words[next].substr(words[next].size()-costs[last][next]);
            last = next;
        }
        return ans;
    }
};

// if there is a substring which occurs in another string we are gonna leave those string alone
// then we will be left with strings which are not in another string

// the brute force way to do this will be this , we can just combine each string on the basis of some permutation then while combining remove the matching prefix and suffix of the string
 
// time complexity of the worst case will be n!*n

// Another way would be to use some graph theory for this
// we can frame this problem as a travelling salesman problem

// let each node be a city and we can connect each city to another city by roads where the cost of the road is the length of the string if we combine both the cities together 
// we can find that cost by 