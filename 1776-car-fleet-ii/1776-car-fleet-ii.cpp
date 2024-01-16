class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector <int> st;
        int n = cars.size();
        vector <double> ans(n);
        for(int i = n-1; i>=0; i--){
            int pos = cars[i][0];
            int speed = cars[i][1];
            while(st.size()){
               int id = st.back();
               int pos1 = cars[id][0];
               int speed1 = cars[id][1];
               if (speed <= speed1 || 1.0 * (pos1 - pos) / (speed - speed1) >= ans[id] && ans[id] > 0)
                    st.pop_back();
                else
                    break;
            }
            if(st.size()){
                int top = st.back();
                ans[i] = ((1.0)*(cars[top][0] - pos))/(speed - cars[top][1]);
            }
            else{
                ans[i] = -1;
            }
            st.push_back(i);
        }
        return ans;
    }
};

// monotonic stack with careful implementation