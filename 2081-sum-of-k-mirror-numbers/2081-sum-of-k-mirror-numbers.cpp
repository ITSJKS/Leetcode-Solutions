bool check = true;
vector <long long> v;
unordered_map <int,vector <long long>> mp;
void solve(int ind, string &t, int len){
    int limit = len/2 -(len%2==0);
    if(ind > limit){
        v.push_back(stoll(t));
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
    for(int i =1; i<=11; i++){
        string t(i,'.');
        solve(0,t,i);
    }
    auto isPd = [&](string &t){
        int i = 0 , j = t.size()-1;
        while(i < j) 
            if(t[i]!=t[j]) return false;
            else i++,j--;
        return true;
    };
    auto check_convert = [&](long long num,int k){
        string t;
        while(num>0){
            t.push_back(num%k);
            num/=k;
        }
        reverse(t.begin(),t.end());
        return isPd(t);
    };
    for(auto &x:v){
        for(int j = 2; j <=9; j++){
            if(mp[j].size()>=30) continue;
            if(check_convert(x,j)) mp[j].push_back(x);
        }
    }
    for(int i =2; i<=9; i++) cout<<mp[i].size()<<endl;
    check = false;
}
class Solution {
public:
    long long kMirror(int k, int n) {
        if(check) find();
        long long sum = 0;
        int cnt = 0;
        for(auto &x:mp[k]){
            sum += x;
            cnt++;
            if(cnt == n) break;
        }
        return sum;
    }
};