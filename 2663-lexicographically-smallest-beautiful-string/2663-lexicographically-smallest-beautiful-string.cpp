class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int idx = -1;
        for(int i = n-1; i>=0; i--){
            for(int j = s[i]-'a'+1; j < k; j++){
                bool check = false;
                if(i-1>=0 && s[i-1] == (j+'a')) check = true;
                if(i-2>=0 && s[i-2] == (j+'a')) check = true;
                if(!check){
                    s[i] = j+'a';
                    idx = i;
                    break;
                }
            }
            if(idx !=-1) break;
        }
        if(idx < 0) return "";
        for(int i = idx+1; i<n; i++){
            for(int j = 0; j <3; j++){
                bool check = false;
                if(i-1>=0 && s[i-1] == (j+'a')) check = true;
                if(i-2>=0 && s[i-2] == (j+'a')) check = true;
                if(!check){
                    s[i] = j+'a';
                    break;
                }
            }
        }
        return s;
    }
};
// answer will not exist if the first character is 
// I will greedily form my answer string 
// at any point if I found that next all character are greater than or equal to k
// then at that point either I will 