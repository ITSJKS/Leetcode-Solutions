class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [&](vector <int> &a, vector <int> &b){
            return b[1] - b[0] < a[1] - a[0];
        };
        sort(tasks.begin(),tasks.end(),cmp);
        int start = tasks[0][1];
        int loan = 0;
        start -= tasks[0][0];
        int n = tasks.size();
        for(int i =1 ; i <n; i++){
            if(tasks[i][1] >= start){
                loan += tasks[i][1] - start;
                start = tasks[i][1] - tasks[i][0];
            } 
            else{
                start -= tasks[i][0];
            }
        }
        return loan + tasks[0][1];
    }
};