class Solution {
public:
    long long numberOfWays(string s) {
        long long count = 0;
        long long count_1 = 0, count_0 = 0;
        for(auto x:s){
            if(x == '1') count_1++;
            else count_0++;
        }
        int n = s.size();
        long long cur_1 = 0, cur_0 = 0;
        for(int i = 0; i <n; i++){
            if(s[i] == '1'){
                count += cur_0*(count_0 - cur_0);
            }
            else{
                count += cur_1*(count_1 - cur_1);
            }
            cur_1 += s[i] == '1';
            cur_0 += s[i] == '0';
        }
        return count;
    }
};