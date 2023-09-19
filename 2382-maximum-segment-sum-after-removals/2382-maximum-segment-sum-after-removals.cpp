class DisjointSet{
    public:
    vector <int> parent;
    vector <int> size;
    vector <long long> sum;
    long long max_sum;
    DisjointSet(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
        sum.resize(n,0);
        max_sum = 0;
    }
    int findUPar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUPar(parent[u]);
    }
    void unionBySize(int u, int v){
        int ulp = findUPar(u);
        int vlp = findUPar(v);
        if(ulp == vlp) return;
        if(size[ulp] < size[vlp]) swap(ulp,vlp);
        size[ulp] += size[vlp];
        parent[vlp] = ulp;
        sum[ulp] += sum[vlp];
        max_sum = max(max_sum,sum[ulp]);
    }
};
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& rmQ) {
        int n = nums.size();
        set <int> st;
        DisjointSet ds(n);
        vector <long long> ans(n);
        for(int i = n-1; i>=0; i--){
            int idx = rmQ[i];
            ans[i] = ds.max_sum;
            ds.sum[idx] = nums[idx];
            ds.max_sum = max(ds.max_sum,ds.sum[idx]);
            if(st.count(idx-1)){
                ds.unionBySize(idx-1,idx);
            }
            if(st.count(idx+1)){
                ds.unionBySize(idx+1,idx);
            }
            st.insert(idx);
        }
        return ans;
    }
};

/* sure shot way to get the answer
// time complexity will be nlogn + qlogn
// segment tree approach to find maximum subarray sum , we can store few things at every node
// we can keep maximum prefix sum , maximum suffix sum , maximum sum , prefix sum , and few more things
// when we will be updating it , we will just combine it using some techniques
*/
/*
Think of some other way to solve it
suppose we have a empty array sum will be 0
then we add first element we will get a component
then we add second element if it connected to previous one 

*/