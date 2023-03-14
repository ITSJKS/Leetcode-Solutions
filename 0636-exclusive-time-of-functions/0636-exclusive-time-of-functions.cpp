class Solution {
public:
    vector <int> parse(string &s){
        int it =s.find(':');
        string s1 = s.substr(0,it);
        int id = stoi(s1);
        string s2 = s.substr(it+1);
        int idx = s2.find(':');
        string s3 = s2.substr(0,idx);
        int end = stoi(s2.substr(idx+1));
        int type = 0;
        if(s3 == "end"){
            type = 1;
        }
        return {id,type,end};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector <int> times(n);
        stack <int> st;
        int last = 0;
        for(auto x:logs){
            vector <int> res = parse(x);
            int id = res[0];
            int type = res[1];
            int time = res[2];
            if(type == 0){
                if(st.size()){ 
                    int id1 = st.top();
                    times[id1]+=(time - last);
                }
                st.push(id);
                last = time;
            }
            else{
                int id_1 = st.top();
                st.pop();
                times[id_1] += (time-last+1);
                last = time+1;
            }
        }
        return times;
    }
};