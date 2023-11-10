bool check = true;
unordered_set <int> v;
map <long long,int> mp;
void solve(int ind, string &t, int len){
    int limit = len/2 -(len%2==0);
    if(ind > limit){
        v.insert(stoi(t));
        return;
    }
    int lb = 0;
    if(ind == 0) lb = 1;
    for(int i = lb; i<=9; i++){
        t[ind] = i+'0';
        t[len-ind-1] = i+'0';
        solve(ind+1,t,len);
    }
}
void find(){
    for(int i =1; i<=9; i++){
        string t(i,'.');
        solve(0,t,i);
    }
    auto isPd = [&](long long num){
        string t = to_string(num);
        int i = 0 , j = t.size()-1;
        while(i < j) 
            if(t[i]!=t[j]) return false;
            else i++,j--;
        return true;
    };
    for(auto &x:v){
        if(v.count(x*1ll*x) || isPd(x*1ll*x))
        mp[x*1ll*x]++;
    }
    int prev = 0;
    for(auto &x:mp){
        x.second += prev;
        prev = x.second;
    }
    check = false;
}
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        if(check) find();
        long long r = stoll(right);
        long long l = stoll(left);
        l--;
        auto rit = mp.upper_bound(r);
        int cnt_r = 0;
        if(rit!=mp.begin()){
            rit--;
            cnt_r = (*rit).second;
        }
        auto lit = mp.upper_bound(l);
        int cnt_l = 0;
        if(lit!=mp.begin()){
            lit--;
            cnt_l = (*lit).second;
        }
        return cnt_r-cnt_l;
    }
};