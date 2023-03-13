class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector <string> ans;
        int j = 0;
        int size = target.size();
        for(int i = 1; i <=n; i++){
            ans.push_back("Push");
            if(target[j] == i){
                j++;
            }
            else{
                ans.push_back("Pop");
            }
            if(j == size) return ans;
        }
        return ans;
    }
};