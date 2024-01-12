class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        // cout<<n<<" ";
        int r = -1;
        auto check = [&](int mid)-> int{
            int cur = n;
            int total = 0;
            int m = mid;
            if(m > limit-3) return -1;
            int start = 1;
            while(cur > 0){
                if(to_string(start).size() > m) return -1;
                int rem = limit - 3 - m-to_string(start).size();
                if(rem <= 0) return -1;
                start++;
                cur -= rem;
            }
            return start-1;
        };
        for(int i = 1; i <=4; i++){
            int cur = check(i);
            if(cur != -1){
                r = cur;
                break;
            }
        }
        if(r  == -1) return {};
        string res = to_string(r);
        vector <string> ans;
        int start = 1;
        int cur = 0;
        for(int j = 0; j <r; j++){
            string t;
            string y = to_string(start);
            int rem = limit - 3 - res.size()- y.size();
            for(int j = cur ; j <min(n,cur+rem); j++){
                t.push_back(message[j]);
            }
            cur += rem;
            t.push_back('<');
            for(auto &ch:y) t.push_back(ch);
            t.push_back('/');
            for(auto &ch:res) t.push_back(ch);
            t.push_back('>');
            ans.push_back(t);
            start++;
        }
        return ans;
    }
};

// we need to find number of splits using binary search
// let number of split be x
// then we will divide our message of size x into 