class Solution {
public:
    int minGroups(vector<vector<int>>& inv) {
        sort(inv.begin(),inv.end());
        multiset <pair <int,int>> st;
        for(auto x:inv){
            st.insert({x[0],x[1]});
        }
        int count = 0;
        for(auto x:inv){
            pair <int,int> p = {x[0],x[1]};
            if(st.find(p)==st.end()) continue;
            count++;
            st.erase(st.find(p));
            while(st.lower_bound({p.second+1,p.second+1})!=st.end()){
                auto it = st.lower_bound({p.second+1,p.second+1});
                p = *it;
                st.erase(it);
            }
        }
        return count;
    }
};

/*

Rough:-
sort by starting time
whenever we need new group we insert new group with start time and end time of interval , and update end time according to need, if we don't find any group with 

Intuition:-

Explanation:-

*/
