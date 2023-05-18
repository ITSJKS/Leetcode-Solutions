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
class SORTracker {
public:
    ordered_set <pair<int,string>> st;
    int idx = 0;
    SORTracker() {
    }
    
    void add(string name, int score) {
        st.insert({-score,name});
    }
    
    string get() {
        idx++;
        return (*st.find_by_order(idx-1)).second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */