typedef pair <int,string>ppi;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector <string> ans;
        unordered_map <string,int>mp;
        auto compare = [](ppi &a,ppi &b){
            if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
        };
        priority_queue <ppi,vector <ppi>,decltype(compare)> pq(compare);
        for(auto x:words){
            mp[x]++;
        }
        for(auto x:mp){
            pq.push({x.second,x.first});
            // if(pq.size()>k) pq.pop();
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};