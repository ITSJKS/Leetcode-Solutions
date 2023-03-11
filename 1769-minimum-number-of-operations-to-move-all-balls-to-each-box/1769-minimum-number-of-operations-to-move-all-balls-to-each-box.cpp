class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.size();
        vector <int> ans(n);
        for(int i = 0; i <n; i++){
            if(boxes[i] == '1'){
                for(int j = 0; j < n; j++){
                    if(i!=j){
                        ans[j] += abs(i - j);
                    }
                }
            }
        }
        return ans;
    }
};