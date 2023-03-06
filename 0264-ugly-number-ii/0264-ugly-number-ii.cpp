class Solution {
public:
    #define ll long long
    int nthUglyNumber(int n) {
        priority_queue <ll,vector<ll>,greater<ll>> pq;
        if(n == 1) return 1;
        pq.push(1);
        ll k = 0;
        set <int> st;
        st.insert(1);
        while(true){
            ll top = pq.top();
            pq.pop();
            k++;
            if(k == n) return top;
            if(st.count(2*top) == 0){
                pq.push(2*top);
                st.insert(2*top);
            }
                if(st.count(3*top) == 0){
                pq.push(3*top);
                st.insert(3*top);
            }
            if(st.count(5*top) == 0){
                pq.push(5*top);
                st.insert(5*top);
            }
        }
        return -1;
    }
};