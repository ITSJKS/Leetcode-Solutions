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
        for (int i = 0; i < n; i++)
        {
            int x = random() % n;
            swap(v[i], v[x]);
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