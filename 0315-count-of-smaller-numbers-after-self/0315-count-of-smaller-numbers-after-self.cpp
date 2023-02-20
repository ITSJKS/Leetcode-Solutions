#include <bits/stdc++.h>
using namespace std;

class MergeSortTree {
private:
    vector<vector<int>> tree;
    int n;

    void build(int l, int r, int node, vector<int>& arr) {
        if (l == r) {
            tree[node].push_back(arr[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, 2 * node, arr);
        build(mid + 1, r, 2 * node + 1, arr);

        tree[node].resize(r - l + 1);
        merge(tree[2 * node].begin(), tree[2 * node].end(),
              tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              tree[node].begin());
    }

    int query(int ql, int qr, int val, int l, int r, int node) {
        if (l > qr || r < ql) {
            return 0;
        }

        if (ql <= l && qr >= r) {
            return upper_bound(tree[node].begin(), tree[node].end(), val-1) - tree[node].begin();
        }

        int mid = (l + r) / 2;
        int left = query(ql, qr, val, l, mid, 2 * node);
        int right = query(ql, qr, val, mid + 1, r, 2 * node + 1);
        return left + right;
    }

public:
    MergeSortTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(0, n - 1, 1, arr);
    }

    int query(int l, int r, int val) {
        return query(l, r, val, 0, n - 1, 1);
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        MergeSortTree st(nums);
        int n = nums.size();
        vector <int> ans(n);
        for(int i = 0; i <n; i++){
            ans[i] = st.query(i+1,n-1,nums[i]);
        }
        return ans;
    }
};