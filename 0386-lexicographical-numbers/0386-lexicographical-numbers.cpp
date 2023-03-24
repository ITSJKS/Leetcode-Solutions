class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector <int> ans;
        int start = 1;
        for(int i = 0; i <n; i++){
            ans.push_back(start);
            start*=10;
            while(start > n){
                start/=10;
                start++;
                while(start%10 == 0){
                    start/=10;
                }
            }
        }
        return ans;

    }
};