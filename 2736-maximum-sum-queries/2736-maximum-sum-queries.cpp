#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree;
    int size;
    
    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size - 1, INT_MIN);
    }

    void build(vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree[x] = a[lx];
            return;
        }
        int m = lx + (rx - lx) / 2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        tree[x] = max(tree[2*x + 1], tree[2*x + 2]);
    }

    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return INT_MIN;
        if (lx >= l && rx <= r) return tree[x];
        int m = lx + (rx - lx) / 2;
        int leftMax = query(l, r, 2*x + 1, lx, m);
        int rightMax = query(l, r, 2*x + 2, m, rx);
        return max(leftMax, rightMax);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    
    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = max(tree[x], v);
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i < m) {
            update(i, v, 2*x + 1, lx, m);
        } else {
            update(i, v, 2*x + 2, m, rx);
        }
        tree[x] = max(tree[2*x + 1], tree[2*x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }
};


class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
      set <int> st1;
        int n = nums1.size();
        int q = queries.size();
      vector <vector <int>> points;
      for(int i = 0; i <n; i++){
          points.push_back({nums1[i],nums2[i],-1});
          st1.insert(nums2[i]);
      }
      for(int i = 0; i <q; i++){
          points.push_back({queries[i][0],queries[i][1],i});
          st1.insert(queries[i][1]);
      }
        unordered_map <int,int> indices;
        int counter = 0;
        for(auto &x:st1){
            indices[x] = counter;
            counter++;
        }
        SegmentTree st(counter);
        auto cmp = [&](vector <int> &p1, vector <int> &p2){
            if(p1[0] == p2[0]){
                if(p1[1] == p2[1]){
                    return p1[2] > p2[2];
                }
                return p1[1] < p2[1];
            }
            return p1[0] < p2[0];
        };
        sort(points.begin(),points.end(),cmp);
        reverse(points.begin(),points.end());
        vector <int> ans(q);
        for(auto &point:points){
            int x = point[0], y = point[1], idx = point[2];
            if(idx == -1){
                st.update(indices[y],x+y);
            }
            else{
                int val = st.query(indices[y],counter);
                if(val < 0)  ans[idx] = -1;
                else ans[idx] = val;
            }
        }
        return ans;
    }
};

// sort by x , then y , then if it's a data or query

// when we are processing a 