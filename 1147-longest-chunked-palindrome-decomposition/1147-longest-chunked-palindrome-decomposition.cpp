class Solution {
public:
    int longestDecomposition(string text) {
        string left = "", right = "";
        int n = text.size();
        int count  = 0;
        for(int i = 0; i <n; i++){
            left += text[i];
            right.insert(right.begin(),text[n-1-i]);
            if(left == right) count++,left = "",right = "";
        }
        return count;
    }
};