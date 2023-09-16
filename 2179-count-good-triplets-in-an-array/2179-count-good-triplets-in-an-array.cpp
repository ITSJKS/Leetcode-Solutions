class FenwickTree{
    vector <int> bit;
    int n;
    public:
    FenwickTree(int size){
        this->n = size+1;
        bit.resize(n,0);
    }
    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector <int> mapping(n);
        // we will keep index of every element in nums2 in map
        for(int i = 0; i < n; i++){
            mapping[nums2[i]] = i;
        }
// find location of the same element in nums2
// then find number of element in nums1 which are in left and also in left of nums2
        FenwickTree ft(n);
        vector <int> left(n);
        for(int i = 0; i <n; i++){
        int idx = mapping[nums1[i]];
        left[i] = ft.sum(idx);
        ft.update(idx,1);
        }
        long long ans = 0;
        FenwickTree ft2(n);
        for(int i = n-1; i>=0; i--){
            int idx = mapping[nums1[i]];
            int cnt = ft2.sum(idx,n-1);
            ans += left[i]*1ll*cnt;
            ft2.update(idx,1);
        }
        return ans;
    }
};


// for every element I can find number of element in it's left which are in left in both and number of element in right which are in right in both
// then we can traverse  the array and find the details