class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rept) {
        int n = s.size();
        string st;
        int cnt_r = 0;
        int cnt_l = 0;
        int s_left = n;
        for(auto &x:s) cnt_r += (x==letter);
        for(int r = 0; r <n; r++){
            char ch = s[r];
            while(!st.empty() && st.back() > ch && (s_left+st.size() > k) && (cnt_l + cnt_r > rept || st.back()!=letter)){
                char x = st.back();
                st.pop_back();
                if(x == letter){
                    cnt_l--;
                }
            }
            if(st.size() < k && (ch == letter || st.size() - cnt_l < k - rept)){
                st.push_back(ch);
                if(ch == letter) cnt_l++;
            }
            if(ch == letter) cnt_r--;
            s_left--;
        }
        return st;
    }
};

/*
We are given a string s, an integer k , a letter and an integer repetition

return lexicographically smallest subsequence of s of length k that has letter appear at least repetition times.

I need a k sized string such that it is smallest one and it contains letter at least k times

we can apply some monotonic stack based approach
we will traverse the string if it the character at the back is greater than current letter and it is okay to pop that one out then we will remove it
then we will push the current character and also check


*/