const int MAXN = 100005;
int n;
unordered_map <int,int> tree[MAXN];

void update(int idx, int val)
{
    while (idx <= n)
    {
        tree[idx][val] += 1;
        idx += idx & -idx;
    }
}

int query_1(int idx,int val)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += tree[idx][val];
        idx -= idx & -idx;
    }
    return sum;
}
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size()+1;
        for(int i = 0; i <n; i++){
            tree[i].clear();
        }
        for(int i = 0; i <n-1; i++){
            update(i+1,arr[i]);
        }
    }
    
    int query(int left, int right, int value) {
        left++;
        right++;
        return query_1(right,value) - query_1(left-1,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */