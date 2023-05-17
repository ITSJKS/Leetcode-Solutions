class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector <int> ans(30,0);
        vector <int> pos(30,0);
        ans[0] = 1;
        for(int i = 1; i <30; i++){
            ans[i]  = ans[i-1] + (1<<i);
        }
        for(int i = 0; i <30; i++){
            if(n&(1<<i)) pos[i]++;
        }
        int cur = 0;
        bool flag = true;
        for(int i = 29; i >=0; i--){
            if(pos[i]){
                if(flag) cur += ans[i];
                else cur -= ans[i];
                flag = !flag;
            }
        }
        return cur;
    }
};

// 32 bits
// 1  0 0 0 0 0  required 1  << (k+1) - 1 operations
// therefore we can convert any number containing 1 0 0 1 0 1
// etc . to zero by doing these operations