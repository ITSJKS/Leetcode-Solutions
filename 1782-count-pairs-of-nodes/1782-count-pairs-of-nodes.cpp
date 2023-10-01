class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector <vector <int>> g(n);
        map <pair<int,int>,int> mp;
        vector <int> indegree(n);
        for(auto &x:edges){
            int u = x[0]-1;
            int v = x[1] -1;
            indegree[u]++;
            indegree[v]++;
            if(u > v) swap(u,v);
            mp[{u,v}]++;
        }
        vector <int> sizes = indegree;
        sort(sizes.begin(),sizes.end());
        int q = queries.size();
        for(auto &x:sizes) cout<<x<<" ";
        cout<<endl;
        vector <int> res(q,0);
        for(int i = 0; i <q; i++){
            int limit = queries[i];
            int count = 0;
            for(int j = 0; j <n; j++){
                auto it = upper_bound(sizes.begin()+j+1,sizes.end(),limit-sizes[j])-sizes.begin();
                count += n - it;
            }
            for(auto &x:mp){
                if(indegree[x.first.first] + indegree[x.first.second ] > limit && indegree[x.first.first] + indegree[x.first.second ] - x.second <= limit) count--;
            }
            res[i] = count;
        }
        return res;
    }
};
/*
Number of nodes that are connected to either node a or b
I can use kind of a two pointer technique
let's suppose we are given queries[j] = 10;
then we need to find pairs such that incident(a,b) > 10
so we can just sort our 


*/