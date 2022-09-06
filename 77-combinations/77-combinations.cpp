class Solution {
    vector <int> subset;
    vector <vector <int>> powerset;
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,0,k);
        return powerset;
    }
    void backtrack(int start,int n,int count, int k){
        if(count == k){
            powerset.push_back(subset);
            return;
        }
        if(start >n) return;
        subset.push_back(start);
        backtrack(start+1,n,count+1,k);
        subset.pop_back();
        backtrack(start+1,n,count,k);
    }
};