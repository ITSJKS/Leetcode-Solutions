class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector <int> ans(n,0);
        if(k == 0) return ans;
        int sum = 0;
        for(int i = 0; i <n; i++){
            code.push_back(code[i]);
            if(i < k) sum += code[i];
        }
        bool neg = false;
        if(k < 0){
            reverse(code.begin(),code.end());
             neg = true;
             k*=-1;
            sum = accumulate(code.begin(),code.begin()+k,0);
        }
        for(int i = n-1; i>=0; i--){
                if(neg)
                ans[n-i-1] = sum;
                else    
                ans[i] = sum;
                sum -= code[i+k];
                sum += code[i];
            }
        return ans;
    }
};