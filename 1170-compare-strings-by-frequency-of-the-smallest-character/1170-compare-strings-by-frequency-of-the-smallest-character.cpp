class Solution {
public:
    int f(string s){
        vector <int> freq(26,0);
        for(auto x:s){
            freq[x-'a']++;
        }
        for(int i = 0; i <26; i++){
            if(freq[i]) return freq[i];
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector <int> f_count;
        for(auto x:words){
            f_count.push_back(f(x));
        }
        sort(f_count.begin(),f_count.end());
        int n = queries.size();
        int m = words.size();
        vector <int> ans(n);
        for(int i = 0; i <n; i++){
            int c = f(queries[i]);
            auto it = upper_bound(f_count.begin(),f_count.end(),c) - f_count.begin();
            ans[i] = m - it;
        }
        return ans;
    }
};