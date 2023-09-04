#define fi       first
#define se       second
#define ll       long long
#define pb       push_back
#define pii      pair<int,int>
#define pll      pair<long long,long long>
#define vi       vector<int>
#define vl       vector<long long>
#define mii      map<int,int>
#define mll      map<long long,long long>
#define qi       queue<int>
#define pqb      priority_queue<int>
#define pqs      priority_queue<int,vi,greater<int> >
#define mod      1000000007
#define inf      INT_MAX
#define ninf      INT_MIN
#define ld       long double
#define f(i,x)     for(int i=0;i<(int)x;i++)
#define rep(i,a,b)   for(int i=(int)a;i<=(int)b;i++)   
#define endl      '\n'
#define all(arr)    arr.begin(),arr.end()
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = accumulate(all(nums),0ll);
        if(sum < target) return -1;
        sort(all(nums));
        int count = 0;
        while(target>0){
            int num = nums.back();
            nums.pop_back();
            if(sum - num >= target) sum -= num;
            else if(num <=target){
                sum -= num;
                target -= num;
            }
            else{
                nums.push_back(num/2);
                nums.push_back(num/2);
                count++;
            }
        }
        return count;
    }
};

// number of operations so that the array contains a subsequence which sums to target
// all the numbers are power of two so we can 

// for 12 -> 1100