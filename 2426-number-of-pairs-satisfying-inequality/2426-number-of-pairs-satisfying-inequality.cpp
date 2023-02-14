#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// int main() {
//     ordered_set <int> a;
//     a.insert(2);
//     a.insert(4);
//     a.insert(3);
//     a.insert(7);
//     a.insert(5);
//     cout << *a.find_by_order(3) << endl; //output is 5
//     cout << (a.order_of_key(10)) << endl; //output is 5
// }
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector <int> diff_array(n);
        for(int i = 0; i <n; i++){
            diff_array[i] = nums1[i]-nums2[i];
        }
        long long count = 0;
        ordered_set <pair <int,int>> st;
        st.insert({diff_array[0],0});
        for(int j = 1; j <n; j++){
            auto it = st.order_of_key({diff_array[j]+diff+1,-1});
            count += it;
            st.insert({diff_array[j],j});
        }
        return count;
    }
};