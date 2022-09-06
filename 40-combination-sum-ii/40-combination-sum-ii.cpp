class Solution {
     vector <vector <int> > powerset;
     vector <int> subset;
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        combination(cand,0,target);
        return powerset;
    }
    void combination(vector <int> &c,int start, int target){
        if(target == 0){
            powerset.push_back(subset);
        }
        int n = c.size();
        if(start == n || target < 0) return;
        for(int i = start; i <n; i++){
            if(i>start && c[i-1]==c[i]) continue;
            subset.push_back(c[i]);
            combination(c,i+1,target-c[i]);
            subset.pop_back();
        }
    }
};