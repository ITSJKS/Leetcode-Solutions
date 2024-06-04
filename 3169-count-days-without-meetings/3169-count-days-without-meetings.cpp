class Solution {
public:
    int countDays(int days, vector<vector<int>>& v) {
    sort(v.begin(), v.end());
    int n = v.size();
    vector <vector <int>> res;
    for (auto interval : v) {
        int sT = interval[0];
        int eT = interval[1];
        if (res.empty() || res.back()[1] < sT) {
            res.push_back(interval);
        }
        else {
            res.back()[1] = max(res.back()[1], eT);
        }
    }
    int count = 0;
    int prev = 0;
    for (int i = 0; i < res.size(); i++) {
        count += max(0, res[i][0] - prev - 1);
        prev = res[i][1];
    }
    count += max(0, days - res.back()[1]);
    return count;
}
};