class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int count = 0,minEnd = INT_MIN,nb = 1;
        for(auto x:intervals){
            if(x[0]>=minEnd){
                count += nb-1;
                nb = 1;
                minEnd = x[1];
            }
            else{
                nb++;
                minEnd = min(minEnd,x[1]);
            }
        }
        return count + nb - 1;
    }
};