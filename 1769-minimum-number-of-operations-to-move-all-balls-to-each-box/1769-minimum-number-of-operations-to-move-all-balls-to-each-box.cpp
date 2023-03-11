class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.size();
        vector <int> ans(n);
        for(int i = 0,c = 0,op = 0; i <n; i++){
            ans[i]+=op;
            c += boxes[i] == '1'?1:0;
            op += c;
        }
        for(int i = n-1,c = 0,op = 0; i >=0 ; i--){
            ans[i]+=op;
            c += boxes[i] == '1'?1:0;
            op += c;
        }
        return ans;
    }
};