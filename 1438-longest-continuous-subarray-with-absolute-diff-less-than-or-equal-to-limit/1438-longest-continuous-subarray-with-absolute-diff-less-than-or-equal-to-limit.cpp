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
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int n = nums.size();
        ordered_set <pair <int,int>> st;
        for(int l =0, r = 0; r<n; r++){
            st.insert({nums[r],r});
            int s = st.size();
            int maxi = (*st.find_by_order(s-1)).first;
            int mini = (*st.find_by_order(0)).first;
            if(maxi - mini <= limit){
                ans = max(ans,r -l + 1);
            }
            else{
                while(maxi - mini > limit){
                    st.erase({nums[l],l});
                     s = st.size();
                    maxi = (*st.find_by_order(s-1)).first;
                    mini = (*st.find_by_order(0)).first;
                    l++;
                }
            }
        }
        return ans;
    }
};