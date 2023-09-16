// class Node{
//     public:
//     char pre,suf;
//     int cnt,pre_cnt, suf_cnt,len;
    
//     Node(){
//         cnt = 0, pre_cnt = 0, suf_cnt = 0, len = 0;
//         pre = '#', suf = '#';
//     }
// };
// class SegmentTree{
//     public:
//     vector <Node> seg;
//     string str;
//     int n;
//     SegmentTree(string &s){
//         this->n = s.size();
//         this->str = s;
//         seg.resize(4*n);
//         build(0,0,n-1);
//     }
//     void build(int node, int l,int r) {
//         if(l == r){
//             seg[node].pre = seg[node].suf = str[l];
//             seg[node].cnt = seg[node].pre_cnt = seg[node].suf_cnt = seg[node].len = 1;
//             return;
//         }
//         int mid = (l+r)/2;
//         build(2*node+1,l,mid);
//         build(2*node+2,mid+1,r);
//         // I have to combine suffix2 and prefix1
//         seg[node].len = seg[2*node+1].len + seg[2*node+2].len;
//         seg[node].cnt = max(seg[2*node+1].cnt,seg[2*node+2].cnt);
//         if(seg[node*2 +1].suf == seg[node*2 + 2].pre){
//             seg[node].cnt = max(seg[node].cnt,seg[2*node+1].suf_cnt + seg[2*node+2].pre_cnt);
//         }
//         seg[node].pre_cnt = seg[2*node+1].pre_cnt;
//         seg[node].suf_cnt = seg[2*node+2].suf_cnt;
//         seg[node].pre = seg[2*node+1].pre;
//         if(seg[2*node+1].len == seg[2*node+1].pre_cnt && seg[2*node+1].suf == seg[2*node+2].pre){
//             seg[node].pre_cnt = max(seg[node].pre_cnt,seg[2*node+1].pre_cnt + seg[2*node+2].pre_cnt);
//         }
//         seg[node].suf = seg[2*node+2].suf;

//          if(seg[2*node+2].len == seg[2*node+2].suf_cnt && seg[2*node+1].pre == seg[2*node+2].suf){
//             seg[node].suf_cnt = max(seg[node].suf_cnt,seg[2*node+1].suf_cnt + seg[2*node+2].suf_cnt);
//         }
//         return;
        
//     }
//     void update(int node, int l, int r, int pos,char ch){
//         if(l == r){
//             seg[node].pre = seg[node].suf = ch;
//             return;
//         }
//         int mid = (l+r)/2;
//         if(pos<=mid) update(2*node+1,l,mid,pos,ch);
//         else update(2*node+2,mid+1,r,pos,ch);
//         seg[node].len = seg[2*node+1].len + seg[2*node+2].len;
//         seg[node].cnt = max(seg[2*node+1].cnt,seg[2*node+2].cnt);
//         if(seg[node*2 +1].suf == seg[node*2 + 2].pre){
//             seg[node].cnt = max(seg[node].cnt,seg[2*node+1].suf_cnt + seg[2*node+2].pre_cnt);
//         }
//         seg[node].pre_cnt = seg[2*node+1].pre_cnt;
//         seg[node].suf_cnt = seg[2*node+2].suf_cnt;
//         seg[node].pre = seg[2*node+1].pre;
//         if(seg[2*node+1].len == seg[2*node+1].pre_cnt && seg[2*node+1].suf == seg[2*node+2].pre){
//             seg[node].pre_cnt = max(seg[node].pre_cnt,seg[2*node+1].pre_cnt + seg[2*node+2].pre_cnt);
//         }
//         seg[node].suf = seg[2*node+2].suf;

//          if(seg[2*node+2].len == seg[2*node+2].suf_cnt && seg[2*node+1].pre == seg[2*node+2].suf){
//             seg[node].suf_cnt = max(seg[node].suf_cnt,seg[2*node+1].suf_cnt + seg[2*node+2].suf_cnt);
//         }
//         return;
//     }
// };
// class Solution {
// public:
//     vector<int> longestRepeating(string s, string qc, vector<int>& ind) {
//         SegmentTree st(s);
//         vector <int> ans;
//         int n = qc.size();
//         for(int i = 0; i <n; i++){
//             st.update(0,0,n-1,ind[i],qc[i]);
//             ans.push_back(st.seg[0].cnt);
//         }
//         return ans;
//     }
// };

// /*
// after every query is performed, I need to find longest substring of s consisting of only one repeating character
// brute force approach
// I will check for the longest Repeating character in the string after every update
// TC -> (O(q*n))

// Optimization
// We can see that for every update 
// we have to find the value using segment tree
// we can store these values in every node
// prefix char ,suffix_char
// prefix_cnt, suffix_cnt
// consecutive same
// suffix_2 + prefix_1 if 
// when we are merging both the nodes
// we will keep prefix_1 with suffix if prefix_char1 == prefix_char2
// we will merge suffix if suffix_2 == suffix_1
// and in final max_consecutive for the node will be max(left,right,prefix,suffix)

// now what to do after update
// when we are updating a node
// we have to do some operation on it

// */

class Block{
public:
    int ans, pf, sf, len;
    char pfc, sfc;

    Block(){
        ans = 0, pf = 0, sf = 0, len = 0;
        pfc = '#', sfc = '#';
    }
};

class Solution {
public:
    void build(string &s, vector<Block> &tree, int st, int emd, int node){
        if(st==emd){
            tree[node].ans = tree[node].pf = tree[node].sf = tree[node].len = 1;
            tree[node].pfc = tree[node].sfc = s[st];
            return;
        }

        int mid = (st+emd)/2;
        build(s, tree, st, mid, 2*node);
        build(s, tree, mid+1, emd, 2*node+1);

        tree[node].len = tree[2*node].len + tree[2*node+1].len;
        tree[node].ans = max(tree[2*node].ans, tree[2*node+1].ans);
        if(tree[2*node].sfc==tree[2*node+1].pfc) tree[node].ans = max(tree[node].ans, tree[2*node].sf+tree[2*node+1].pf);
        tree[node].pfc = tree[2*node].pfc, tree[node].sfc = tree[2*node+1].sfc;

        tree[node].pf = tree[2*node].pf;
        if(tree[2*node].pf==tree[2*node].len && tree[2*node].sfc==tree[2*node+1].pfc)
            tree[node].pf = max(tree[node].pf, tree[2*node].len + tree[2*node+1].pf);

        tree[node].sf = tree[2*node+1].sf;
        if(tree[2*node+1].len == tree[2*node+1].sf && tree[2*node+1].pfc==tree[2*node].sfc)
            tree[node].sf = max(tree[node].sf, tree[2*node+1].len + tree[2*node].sf);
    }

    void update(vector<Block> &tree, int st, int emd, int node, int idx, char ch){
        if(st==emd){
            tree[node].pfc = tree[node].sfc = ch;
            return;
        }

        int mid = (st+emd)/2;
        if(idx<=mid) update(tree, st, mid, 2*node, idx, ch);
        else update(tree, mid+1, emd, 2*node+1, idx, ch);

        tree[node].len = tree[2*node].len + tree[2*node+1].len;
        tree[node].ans = max(tree[2*node].ans, tree[2*node+1].ans);
        if(tree[2*node].sfc==tree[2*node+1].pfc) tree[node].ans = max(tree[node].ans, tree[2*node].sf+tree[2*node+1].pf);
        tree[node].pfc = tree[2*node].pfc, tree[node].sfc = tree[2*node+1].sfc;

        tree[node].pf = tree[2*node].pf;
        if(tree[2*node].pf==tree[2*node].len && tree[2*node].sfc==tree[2*node+1].pfc)
            tree[node].pf = max(tree[node].pf, tree[2*node].len + tree[2*node+1].pf);

        tree[node].sf = tree[2*node+1].sf;
        if(tree[2*node+1].len == tree[2*node+1].sf && tree[2*node+1].pfc==tree[2*node].sfc)
            tree[node].sf = max(tree[node].sf, tree[2*node+1].len + tree[2*node].sf);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        vector<Block> tree(4*n);

        build(s, tree, 0, n-1, 1);

        int q = queryIndices.size();
        vector<int> ans;
        for(int i=0;i<q;i++){
            update(tree, 0, n-1, 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].ans);
        }

        return ans;
    }
};