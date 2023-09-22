class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector <int> perm;
        for(int i =1; i<=m; i++){
            perm.push_back(i);
        }
        int q = queries.size();
        vector <int> ans;
        for(int i = 0; i <q; i++){
            int num = queries[i];
            int idx;
            for(int j = 0; j <m; j++){
                if(num == perm[j]){
                    idx = j;
                    break;
                }
            }
            perm.erase(perm.begin()+idx);
            perm.insert(perm.begin(),num);
            ans.push_back(idx);
        }
        return ans;
    }
};

/*
Given the array queries of postive integers between 1 and m
we have to process all queries
we have a permuation 1 to m
for current i , find the position of queries[i] in the permutation p , and then move this at the beginning of the permutation P
result is position of queries[i] in P

3 1 2 4 5

3 -> 2


*/