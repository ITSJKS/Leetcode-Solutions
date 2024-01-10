class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> st;
        for(auto &x:forbidden) st.insert(x);
        string cur;
        int ans = 0;
        int n = word.size();
        for(int r =0 ; r <n; r++){
            cur += word[r];
            int m = cur.size();
            string temp;
            for(int j = m-1; j>=max(0,m-10); j--){
                string prev = temp;
                temp = cur[j] + temp;
                if(st.count(temp)){
                    cur = prev;
                    break;
                }
            }
            ans = max(ans,(int)cur.size());
        }
        return ans;
    }
};

// a string is called valid if none of it's substring are present in forbidden
// we need to return the length of longest valid substring of the string word
// approach
// we can apply sliding window here
// let our cur satisfied window be l....r
// if by adding r+1 , if our window is getting invalid then we will have to skip entire window and start from string 
