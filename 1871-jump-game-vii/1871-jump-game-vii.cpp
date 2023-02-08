class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1] == '1') return false;
        vector <int> prefix(n,0);
        for(int i = 0; i <n; i++){
            if(i>0){
                prefix[i]+=prefix[i-1];
            }
            if(s[i]=='0' && (i==0 || prefix[i]>0)){
                if(i+minJump < n){
                    prefix[i+minJump]+=1;
                }
                if(i+maxJump+1 < n){
                    prefix[i+maxJump+1]-=1;
                }
            }
        }
        return prefix[n-1]>0;
    }
};