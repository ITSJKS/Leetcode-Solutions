#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Working of pbds
//     ordered_set <int> a;
//     a.insert(2);
//     a.insert(4);
//     a.insert(3);
//     a.insert(7);
//     a.insert(5);
//     cout << *a.find_by_order(3) << endl; //output is 5
//     cout << (a.order_of_key(10)) << endl; //output is 5
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ordered_set <pair<int,int>> st;
        vector <int> ans(n,0);
        for(int i = n-1; i >=0; i--){
            ans[i] = st.order_of_key({nums[i],-1});
            st.insert({nums[i],i});
        }
        return ans;
    }
};