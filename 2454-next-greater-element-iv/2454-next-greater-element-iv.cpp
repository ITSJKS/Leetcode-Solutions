class SegmentTree{
    public:
    vector <int> seg;
    vector <int> a;
    int n;
    SegmentTree(vector <int>&arr){
        a = arr;
        n = a.size();
        seg.resize(4*n);
        build(0,0,n-1);
    }
    void build(int node, int l, int r){
        if(l == r){
            seg[node] = a[l];
            return;
        }
        int mid = l + (r  - l)/2;
        build(2*node+1,l,mid);
        build(2*node+2,mid+1,r);
        seg[node] = max(seg[2*node+1],seg[2*node+2]);
    }
     int query(int node,int lo,int hi,int l,int r){
        if(lo>=l && hi<=r){
            return seg[node];
        }
        if(hi<l || lo>r){
            return 0;
        }
        int mid = lo + (hi-lo)/2;
        int left = query(2*node+1,lo,mid,l,r);
        int right = query(2*node+2,mid+1,hi,l,r);
        return max(left,right);
    }
};
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(nums);
        vector <int> ans(n,-1);
        vector <int> st;
        for(int i = 0; i <n; i++){
            while(!st.empty() && nums[st.back()] < nums[i]){
                ans[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        for(int i = 0; i <n; i++){
            int ngr = ans[i];
            if(ngr!=-1){
                int l = ngr+1, r = n-1;
                int res = -1;
                while(l<=r){
                    int mid = l + (r-l)/2;
                    if(seg.query(0,0,n-1,l,mid)>nums[i]){
                        res = mid;
                        r = mid-1;
                    }
                    else{
                        l = mid+1;
                    }
                }
                if(res != -1 && nums[res] > nums[i] ) ans[i] = nums[res];
                else ans[i] = -1;
            }
        }
        return ans;
    }
};

// Can we apply binary search on the monotonic stack
// suppose the array is 
/*
 2   4 0 9 6 ->

// I can try to find next greater element between ngr[i] + 1, n-1 using binary search
// I will first calculate if there is a value greater than num between l and mid if there is we will keep our r  as mid-1 and ans = mid,  else l as mid+1

*/