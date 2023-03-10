class Solution {
public:
    vector <long long> score;
    int n;
    int dfs(int src, vector <int> tree[]){
        int count = 0;
        long long product = 1;
        for(auto nbr:tree[src]){
            int left = dfs(nbr,tree);
            count += left;
            if(left != 0) product=product*1ll*left;
        }
        int up = 1;
        up = max(up,n - count - 1);
        score[src] = product*1ll*up;
        count++;
        return count;
        
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        score.resize(n);
        vector <int> tree[n];
        for(int i = 1; i <n; i++){
            tree[parents[i]].push_back(i);
        }
        dfs(0,tree);
        sort(score.begin(),score.end());
        long long maxi = score[n-1];
        int count = 0;
        for(int i = n-1; i>=0; i--){
            if(score[i] == maxi) count++;
            else break;
        }
        return count;
    }
};