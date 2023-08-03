class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string dir) {
        int n = positions.size();
        vector <pair<int,pair<int,char>>> robots;
        map <int,int> idx;
        for(int i = 0; i <n; i++){
            robots.push_back({positions[i],{healths[i],dir[i]}});
            idx[positions[i]] = i;
        }
        sort(robots.begin(),robots.end());
        stack <pair<int,pair<int,char>>> st;
        vector <pair<int,pair<int,char>>> ans;
        for(int i = n-1; i >=0; i--){
            if(robots[i].second.second == 'R'){
                if(st.size()){
                    bool cur = true;
                    while(cur){
                        auto top  =st.top();
                        if(top.second.first > robots[i].second.first){
                            st.top().second.first -=1;
                            cur= false;
                        }
                        else if(top.second.first == robots[i].second.first){
                            st.pop();
                            cur= false;
                        }
                        else{
                            st.pop();
                            robots[i].second.first--;
                            if(st.size() == 0){
                            ans.push_back(robots[i]);
                            cur = false;
                        }
                        }
                        
                    }
                }
                else{
                    ans.push_back(robots[i]);
                }
            }
            else{
                st.push(robots[i]);
            }
        }
        while(!st.empty()) ans.push_back(st.top()),st.pop();
        // for(auto &x:ans) cout<<x.first<<" "<<x.second.first<<endl;
        auto cmp = [&](pair<int,pair<int,char>> &a, pair<int,pair<int,char>> &b){
            return idx[a.first] < idx[b.first];
        };
        sort(ans.begin(),ans.end(),cmp);
        vector <int> res;
        for(auto &x:ans){
            res.push_back(x.second.first);
        }
        return res;
    }
};

// we can use monotonic stack here
// we can start from the back and if it is left , we can keep it in stack , whenever we will get right we will pop our top and check who is greater and then decide who will survive based on that