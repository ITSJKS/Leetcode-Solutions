class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        int j = 0;
        bool turn = true;
        while(i < n && j < m){
            if(turn){
                ans.push_back(word1[i]);
                i++;
                turn = false;
            }
            else{
                ans.push_back(word2[j]);
                j++;
                turn = true;
            }
        }
        while(i < n){
            ans.push_back(word1[i]);
            i++;
        }
        while(j < m){
            ans.push_back(word2[j]);
            j++;
        }
        return ans;
    }
};