class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        auto cmp = [&](vector <int>&a,vector <int>&b){
          return a[0] > b[0];  
        };
        sort(items.begin(),items.end(),cmp);
        long long ans = 0;
        long long sum = 0;
        set <int> st;
        vector <int> dup;
        for(int i = 0 ;i <k; i++){
            sum += items[i][0];
            if(st.count(items[i][1])) dup.push_back(items[i][0]);
            else st.insert(items[i][1]);
        }
        int len = st.size();
        ans = sum + len*1ll*len;
        int n  = items.size();
        for(int i  = k; i < n; i++){
            if(st.count(items[i][1]) == 0 && dup.size()){
                sum -= dup.back();
                dup.pop_back();
                sum += items[i][0];
                st.insert(items[i][1]);
                len = st.size();
                ans = max(ans,sum + len*1ll*len);
            }
        }
        return ans;
    }
};

// I have to be greedy 
// for picking k items out of n items
// I can pick the best k items , then I can pick next 