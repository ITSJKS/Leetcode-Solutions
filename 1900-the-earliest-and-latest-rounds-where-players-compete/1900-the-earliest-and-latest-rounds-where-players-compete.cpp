class Solution {
public:
    unordered_set <string> vis;
    void solve(string s,int depth,int &mini, int &maxi){
        if(depth>=100) return;
        int n = s.size();
        for(int i = 0; i <n/2; i++){
            if(s[i] == '1' && s[n-i-1] == '1'){
                mini = min(mini,depth);
                maxi = max(maxi,depth);
                return;
            }
        }
        if(vis.count(s)) return;
        int half = n/2;
        int total_mask = (1<<half);
        for(int i = 0; i <total_mask; i++){
            string first_half;
            string second_half;
            bool check = true;
            for(int j = 0; j <half; j++){
                if(i&(1<<j) && s[n-j-1] == '1'){
                    check = false;
                    break;
                }
                if((i&(1<<j)==0) && s[j]=='1'){
                    check = false;
                    break;
                }
                if(i&(1<<j)) first_half.push_back(s[j]);
                else second_half.push_back(s[n-j-1]);
            }
            if(!check) continue;
            reverse(second_half.begin(),second_half.end());
            if(n&1) first_half.push_back(s[half]);
            for(auto &x:second_half) first_half.push_back(x);
            solve(first_half,depth+1,mini,maxi);
        }
        vis.insert(s);
    }
    vector<int> earliestAndLatest(int n, int fp, int sp) {
        string str;
        for(int i = 1; i <=n; i++){
            if(i == fp || i == sp) str.push_back('1');
            else str.push_back('0');
        }
        int maxi = 0;
        int mini = INT_MAX;
        solve(str,1,mini,maxi);
        return {mini,maxi};
        
    }
};