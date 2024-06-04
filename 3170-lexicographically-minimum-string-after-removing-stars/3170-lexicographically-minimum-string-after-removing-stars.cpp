class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char,int> , vector<pair<char,int>>, greater<pair<char,int>> > p;
        vector <int> vis(n,0);
        int idx = 0;
        for(auto &x:s){
            if(x == '*'){
                if(p.size()){
                    auto top = p.top();
                    // cout<<top.second<<endl;
                    p.pop();
                    vis[-top.second] = 1;
                }
            }
            else{
                p.push({x,-idx});
            }
            idx++;
        }
        string res;
        for(int i = 0; i <n; i++){
            if(vis[i] == 0 && s[i]!='*') res += s[i];
        }
        return res;
    }
};