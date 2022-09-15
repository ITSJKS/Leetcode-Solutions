class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2 != 0) return {};
        vector <int> ans;
        multiset <int> mst(changed.begin(),changed.end());
        while(mst.size()){
            auto it = *mst.begin();
            ans.push_back(it);
            mst.erase(mst.begin());
            if(mst.find(2*it)==mst.end()) return {};
            mst.erase(mst.find(2*it));  
        }
        return ans;
    }
};