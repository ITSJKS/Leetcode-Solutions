#define int long long
const int mod = 1e9 + 7;
// at each node we need sum of squares in the range and sum of values in the range
struct node{
    int lazy;
    int secondSum;
    int firstSum;
    void set(int x){
        lazy = 0;
        secondSum = x*x%mod;
        firstSum = x%mod;
    }
};
const int N = 1e5 + 10;
int base[N];
node t[4*N];
void push(int idx, int l, int r){
    if(t[idx].lazy){
        int lazy_val = t[idx].lazy;
        t[idx].secondSum += (((lazy_val*lazy_val)%mod*(r-l+1))%mod + (2*t[idx].firstSum*lazy_val)%mod)%mod;
        t[idx].firstSum += lazy_val*(r-l+1)%mod;
        t[idx].firstSum%=mod;
        t[idx].secondSum%=mod;
        if(l!=r){
            t[idx<<1].lazy += lazy_val;
            t[idx<<1 | 1].lazy += lazy_val;
        }
        t[idx].lazy = 0; 
    }
}
node merge(node a, node b){
    node ans;
    ans.firstSum = (a.firstSum + b.firstSum)%mod;
    ans.secondSum = (a.secondSum + b.secondSum)%mod;
    ans.lazy = 0;
    return ans;
}
void build(int idx, int l, int r){
    if(l == r){
        t[idx].set(0);
        return;
    }
    int mid = (l+r)>>1;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    t[idx] = merge(t[idx<<1],t[idx<<1 |1]);   
}
void update(int idx, int l, int r, int lq, int rq, int x){
    push(idx,l,r);
    if(lq > r || l > rq) return;
    if(lq <= l && rq >= r){
        t[idx].lazy += x;
        push(idx,l,r);
        return;
    }
    int mid = (l+r)>>1;
    update(idx<<1,l,mid,lq,rq,x);
    update(idx<<1 |1,mid+1,r,lq,rq,x);
    t[idx] = merge(t[idx<<1],t[idx<<1|1]);
    
}
node query(int idx, int l, int r, int lq, int rq){
    push(idx,l,r);
    if(lq>r || l > rq){
        node temp;
        temp.set(0);
        return temp;
    }
    if(lq <=l && r <= rq){
        return t[idx];
    }
    int mid =(l+r)>>1;
    return merge(query(idx<<1,l,mid,lq,rq),query(idx<<1|1,mid+1,r,lq,rq));
}
#undef int
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        build(1,0,n-1);
        long long ans = 0;
        map <int,int> last_seen;
        for(int i = 0; i <n; i++){
            int prev = -1;
            if(last_seen.count(nums[i])) prev = last_seen[nums[i]];
            update(1,0,n-1,prev+1,i,1);
            ans = (ans + query(1,0,n-1,0,i).secondSum)%mod;
            last_seen[nums[i]] = i;
        }
        return ans;
    }
};

/*
I need to find square of distinct counts of all subarrays of nums
there are n*(n+1)/2 subarrays and in each subarray there will be some distinct integers we need to find sum of squares of those numbers 
if we only needed to find sum of distinct count we could have done something like two pointer or contribution technique but as we have to find sum of squares of distinct count we will need to try some another approahc

we can find number of distinct subarray we will obtain after adding the current element 
we can do this by using segment tree as well as index of last occurence



*/