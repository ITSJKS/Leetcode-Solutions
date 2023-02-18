class Solution {
public:
int a[100005],seg[4*100005] = {},lazy[4*100005] = {};
void build(int ind, int low, int high){
  if(low == high){
    seg[ind] = a[low];
    return;
  }
  int mid = (low + high)/2;
  build(2*ind + 1,low,mid);
  build(2*ind + 2, mid + 1,high);
  int left = seg[2*ind+1];
  int right = seg[2*ind+2];
  // to find sum 
  seg[ind] = left + right;
  // seg[ind] = max(left,right);
}
int rangeUpdate(int ind, int low, int high, int l, int r, int val){
  if(low > r || high < l){
      return lazy[ind] ? high - low + 1 - seg[ind] : seg[ind];
  }
  if(lazy[ind]){
    seg[ind] = (high-low+1) - seg[ind];
    if(low!=high){
      lazy[2*ind+1] = !lazy[2*ind+1];
      lazy[2*ind+2] = !lazy[2*ind+2];
    }
    lazy[ind] = 0;
  }
  if(low>=l && high<=r){
    if(low!=high){
      lazy[2*ind+1] = !lazy[2*ind+1];
      lazy[2*ind+2] = !lazy[2*ind+2];
    }
    return seg[ind] = high - low + 1 - seg[ind];
  }
  int mid = (low + high) / 2;
  int left = rangeUpdate(2*ind+1,low,mid,l,r,val);
  int right = rangeUpdate(2*ind+2,mid+1,high,l,r,val);
  return seg[ind] = left + right;
}
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector <long long> ans;
        memset(lazy,0,sizeof lazy);
        int n = nums1.size();
        for(int i = 0; i <nums1.size(); i++){
            a[i] = nums1[i];
        }
        build(0,0,n-1);
        long long sum = accumulate(nums2.begin(),nums2.end(),0ll);
        for(auto q:queries){
            int type =q[0];
            if(type == 1){
                int l = q[1] , r = q[2];
                rangeUpdate(0,0,n-1,l,r,0);
            }
            else if(type == 2){
                long long p = q[1];
                sum += (long long)(seg[0]*1ll*p);
            }
            else{
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
