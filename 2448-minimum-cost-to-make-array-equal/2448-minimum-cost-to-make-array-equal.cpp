class Solution {
public:
    long long find_cost(vector<pair <long long , long long> > &v,long long pivot){
        long long cost = 0;
        for(auto x:v){
            cost += (abs(x.second - pivot))*(x.first);
        }
        return cost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector <pair <long long,long long>> v;
        for(int i = 0; i <n; i++){
            v.push_back({cost[i],nums[i]});
        }
        sort(nums.begin(),nums.end());
        long long l = nums[0],h = nums[n-1];
        long long ans = find_cost(v,l);
        while(l<h){
            long long mid = (l+h)/2;
            long long y1 = find_cost(v,mid), y2 = find_cost(v,mid+1);
            ans = min(y1,y2);
            if(y1<y2) h = mid;
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};