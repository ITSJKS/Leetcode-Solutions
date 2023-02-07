class Solution {
public:
    int func(vector <int> &v,int l, int r){
        return upper_bound(v.begin(),v.end(), r) - lower_bound(v.begin(),v.end(),l);
    }
    int maximizeWin(vector<int>& pp, int k) {
        map <int,int> mp;
        for(auto x:pp) mp[x]++;
        vector <int> w;
        for(auto x:mp) w.push_back(x.first);
        int maxi = 0;
        int max_prev = 0;
        int n = w.size();
        for(int i = n-1; i >=0; i--){
            maxi = max(maxi,max_prev + func(pp,w[i]-k,w[i]));
            max_prev = max(max_prev,func(pp,w[i],w[i]+k));
            // cout<<maxi<<" "<<max_prev<<endl;
        }
        return maxi;
    }
};