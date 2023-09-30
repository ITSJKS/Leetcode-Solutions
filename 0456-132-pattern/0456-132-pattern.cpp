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
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefix(n,1e9);
        ordered_set <pair<int,int>> st;
        
        for(int i = 0; i<n; i++){
            if(i == 0) prefix[0] = nums[0];
            else prefix[i] = min(prefix[i-1],nums[i]),st.insert({nums[i],i});
        }
        for(int i = 1; i <n-1; i++){
            if(nums[i] > prefix[i-1]){
                int maxi = nums[i];
                int mini = prefix[i-1];
                int cnt1 = st.order_of_key({maxi-1,1e9});
                int cnt2 = st.order_of_key({mini,1e9});
                if(cnt1-cnt2>0) return true;
            }
            st.erase({nums[i],i});
        }
        return false;
    }
};