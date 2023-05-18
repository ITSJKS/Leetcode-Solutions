class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector <int> v;
        int n = heights.size();
        vector <int> ans(n,0);
        for(int i = n-1; i>=0; i--){
            int num = heights[i];
            int count = 0;
            while(v.size() && v.back()<num){
                count++;
                v.pop_back();
            }
            if(v.size()) count++; // we can see one more person
            ans[i] = count;
            v.push_back(num);
        }
        return ans;
    }
};

// 10  6 8 5 11 9