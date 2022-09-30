class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector <vector <int>> points1,ans;
        multiset <int> pq{0};
        for(auto x:buildings){
            points1.push_back({x[0],-x[2]});
            points1.push_back({x[1],x[2]});
        }
        sort(points1.begin(),points1.end());
        int max_h = 0, cur_p, cur_h;
        for(int i = 0; i <points1.size(); i++){
            cur_p = points1[i][0];
            cur_h = points1[i][1];
            if(cur_h <0){
                pq.insert(-cur_h);
            }
            else{
                pq.erase(pq.find(cur_h));
            }
            int top = *pq.rbegin();
            if(top != max_h){
                max_h = top;
                ans.push_back({cur_p,max_h});
                
            }
        }
        return ans;
    }
};