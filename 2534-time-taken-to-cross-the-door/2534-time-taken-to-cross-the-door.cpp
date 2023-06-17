class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        const int n = state.size();
        res.resize(n);
        for(int i=0;i<=n;i++){
            int t_i = i < n ? arrival[i] : 1e9;
            int state_i = i < n ? state[i] : 0;
            while(t<t_i && (!qs[0].empty() || !qs[1].empty())){
                if(!qs[0].empty() && qs[1].empty()) pass(0);
                else if(qs[0].empty() && !qs[1].empty()) pass(1);
                else pass(st);
            }
            if(t<t_i) t = t_i, st = 1;
            qs[state_i].push(i);
        }
        return res;
    }

    void pass(int inOut){
        auto& q = qs[inOut];
        auto i = q.front();
        q.pop();
        res[i] = t++;
        st = inOut;
    }

    vector<int> res;
    queue<int> qs[2]; // queue for in and out
    int st = 1; //door state
    int t = 0;
};