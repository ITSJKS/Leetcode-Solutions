class Solution {
public:
    int minimumSwap(string s1, string s2) {
        map <string,int> mp;
        int n = s1.size();
        int cnt = 0;
        for(int i = 0; i <n; i++){
            if(s1[i]!=s2[i]){
                if(s1[i] == 'x')
                    mp["xy"]++;
                else mp["yx"]++;
                cnt++;
            }
            
        }
        if(cnt&1) return -1;
        int a = mp["xy"];
        int b = mp["yx"];
        return a/2 + b/2 + 2*(a-2*(a/2) + b - (2*b/2));
    }
    
};