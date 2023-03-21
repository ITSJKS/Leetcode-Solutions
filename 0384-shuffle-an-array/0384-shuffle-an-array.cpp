class Solution
{
    public:
        vector<int> initial;
    vector<int> v;
    Solution(vector<int> &nums)
    {
        v = nums;
        initial = v;
    }

    vector<int> reset()
    {
        v = initial;
        return v;
    }

    vector<int> shuffle()
    {

        int n = v.size();
        int size = n;
        for (int i = n-1; i >=0; i--)
        {
            int x = random() % size;
            swap(v[i], v[x]);
            size--;
        }
        return v;
    }
};

/**
 *Your Solution object will be instantiated and called as such:
 *Solution* obj = new Solution(nums);
 *vector<int> param_1 = obj->reset();
 *vector<int> param_2 = obj->shuffle();
 */