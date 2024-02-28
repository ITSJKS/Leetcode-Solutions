class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        for(int i = 0; i <n; i++){
            int left = n - i - 1;
            for(int j = 0; j <26; j++){
                int rem = k - j - 1;
                if(rem > 26*left || rem < left){
                    continue;
                }
                else{
                    k -= (j+1);
                    s.push_back(j+'a');
                    break;
                }
            }
        }
        return s;
    }
};