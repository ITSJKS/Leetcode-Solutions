class Solution {
public:
    int reinitializePermutation(int n) {
        vector <int> init(n),v(n);
        for(int i = 0; i <n; i++){
            init[i] = i;
            v[i] = i;
        }
        int cnt = 1;
        while(true){
            vector <int> new_v(n);
            for(int i = 0; i <n; i++){
                if(i%2 == 0) new_v[i] = v[i/2];
                else{
                    new_v[i] = v[n/2 + (i-1)/2];
                }
            }
            if(new_v == init) return cnt;
            v = new_v;
            cnt++;
        }
        return cnt;
    }
};