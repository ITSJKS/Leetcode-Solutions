class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        int mini = *min_element(sums.begin(),sums.end());
        for(auto &x:sums) x += -mini;
        multiset <int> st(sums.begin(),sums.end()),temp;
        vector <int> ans;
        for(int i  =0; i <n; i++){
            int num = *next(st.begin());
            ans.push_back(num);
            temp.clear();
            while(st.size()){
                auto front = *st.begin();
                temp.insert(front);
                st.erase(st.begin());
                st.erase(st.find(num + front));
            }
            swap(temp,st);
        }
        for(int j = 0; j <(1<<n); j++){
            int cur = 0;
            for(int k = 0; k <n; k++){
                if(j&(1<<k)) cur += ans[k];
            }
            if(cur == (-mini)){
                for(int k = 0; k <n; k++){
                    if(j&(1<<k)) ans[k]*=-1;
                }
                return ans;
            }
        }
        return ans;
    }
};

//  - 3 -2 -1 0 0 1 2 3
/*
If I add -3 (least negative) to all the numbers then I will just have to find an array of positive number 
if in that positive array if i am able to find a subset which is equal to that shifted sum 
then I can just change those number to negative


*/