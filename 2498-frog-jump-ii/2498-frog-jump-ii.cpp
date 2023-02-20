class Solution {
public:
    int maxJump(vector<int>& stones) {
        // binary search
        // we can check if a particular jump is valid by being greedy 
        auto check = [&](int mid){
            set <int> st;
            int cur = 0;
            while(cur+mid<stones.back()){
                auto it = upper_bound(stones.begin(),stones.end(),cur+mid);
                it--;
                if(*it == cur) return false;
                cur = *it;
                st.insert(cur);
            }
            vector <int> left_stones;
            for(auto x:stones){
                if(st.count(x)==0) left_stones.push_back(x);
            }
            int maxi = 0;
            for(int i =1; i <left_stones.size(); i++){
                maxi = max(maxi,left_stones[i]-left_stones[i-1]);
            }
            return maxi <=mid;
            
        };
        int l = 0, r = stones.back()+1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};