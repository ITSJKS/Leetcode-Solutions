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
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        ordered_set <int> st;
        long long count = 0;
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int k = n-1; k >j; k--){
                if(nums[k] < nums[j]){
                    // number of element between 0 to j which are less than nums[k] -> possible l
                    long long a1 = st.order_of_key(nums[k]);
                    // number of element between n-1 to k which are greater than nums[k] -> possible l
                    long long a2 = cnt;
                    count += (a1*1ll*a2);
                }
                else{
                    cnt++;
                }
            }
            st.insert(nums[j]);
        }
        return count;
    }
};

