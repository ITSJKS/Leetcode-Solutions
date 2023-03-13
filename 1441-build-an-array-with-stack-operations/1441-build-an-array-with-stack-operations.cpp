class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector <string> ans;
        int j = 0,i=1;
        int size = target.size();
        while(j < size){
            ans.push_back("Push");
            if(target[j] == i){
                j++;
            }
            else{
                ans.push_back("Pop");
            }
            i++;
        }
        return ans;
    }
};