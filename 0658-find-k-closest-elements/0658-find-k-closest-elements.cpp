class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         priority_queue <pair <int,int> > maxh;
        vector <int> v;
        for(auto num:arr){
            int d = abs(num-x);
            maxh.push({d,num});
            if(maxh.size()>k) maxh.pop();
        }
        while(maxh.size()){
            v.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};