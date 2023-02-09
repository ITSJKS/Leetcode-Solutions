class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        set <int> st;
        map <int,int> mp1,mp2;
        for(auto x:basket1){
            mp1[x]++;
            st.insert(x);
        }
        for(auto x:basket2){
            mp2[x]++;
            st.insert(x);
        }
        vector <int> diff1,diff2;
        for(auto x:st){
            int cnt1 = mp1[x], cnt2 = mp2[x];
            int diff = abs(cnt1-cnt2);
            if(cnt1 == cnt2) continue;
            if(diff%2){
                return -1;
            }
            if(cnt1>cnt2){
                for(int i = 0; i <diff/2; i++){
                    diff1.push_back(x);
                }
            }
            else{
                for(int i =0; i <diff/2; i++){
                    diff2.push_back(x);
                }
            }
        }
        if(diff1.size()!=diff2.size()) return -1;
        long long count = 0;
        int mini = *st.begin();
        int n = diff1.size();
        reverse(diff2.begin(),diff2.end());
        for(int i = 0; i <n; i++){
            count += min(2*mini,min(diff1[i],diff2[i]));
        }
        return count;
    }
};