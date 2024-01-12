#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Working of pbds
//     ordered_set <int> a;
//     a.insert(2);
//     cout << *a.find_by_order(3) << endl; //output is 5
//     cout << (a.order_of_key(10)) << endl; //output is 5
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto cmp = [&](vector <int>&a,vector <int>&b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        ordered_set <int> st;
        int n = intervals.size();
        for(int i = 0; i <n; i++){
            int l = intervals[i][0],r = intervals[i][1];
            int cnt = st.order_of_key(r+1)-st.order_of_key(l);
            int rem = max(0,2-cnt);
            for(int j = r; j>=l; j--){
                if(rem == 0) break;
                if(st.find(j) == st.end()){
                    st.insert(j);
                    rem--;
                }
            }
        }
        return st.size();
    }
};
/*
we are given 2D integer array intervals where intervals[i] = [starti,endi]



*/