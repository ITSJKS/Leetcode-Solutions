class SegmentTree{
    public:
    vector <int> tree;
    int n;
    SegmentTree(int size){
        tree.resize(4*n,-1e9);
        this->n = size;
    }
    void update(int node, int l , int r, int pos, int val){
        if(l == r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <=mid) update(2*node+1,l,mid,pos,val);
        else update(2*node+2,mid+1,r,pos,val);
        tree[node] = max(tree[2*node+1],tree[2*node+2]);
    }
    int query(int node, int l, int r, int ql, int qr){
        if(ql > qr) return -1e9;
        if(l == ql && r == qr){
            return tree[node];
        }
        int mid =  (l+r)/2;
        return max(query(2*node+1,l,mid,ql,min(qr,mid)) , query(2*node+2,mid+1,r,max(mid+1,ql),qr)); 
    }
};
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(n);
        int ans = -1e9;
        for(int i = 0; i <n; i++){
            int cur = nums[i];
            if(i > 0){
                cur  += max(0,st.query(0,0,n-1,max(0,i-k),i));
            }
            ans = max(ans,cur);
            st.update(0,0,n-1,i,cur);
        }
        return ans;
    }
};

/*
we are given an integer array nums and an integer k 
we need to return maximum sum of a non empty subsequence of that array such that every two consecutive integers in the subsequnce, j -i <= k

okay so we can pick element from the array such that no two element is more than k distance apart
atmost k -1 element can be skipped
so we can apply dp here
for each index
yeah we can apply segment tree here
we can update value at index when we get there and then we can find maximum element from index - k to index -1 and update the value there

*/