class Solution
{
    public:
        vector<int> executeInstructions(int n, vector<int> &startPos, string s)
        {
            int m = s.size();
            vector<int> ans(m);
            for (int i = 0; i < m; i++)
            {
                int x = startPos[1], y = startPos[0];
                int count = 0;
                for (int j = i; j < m; j++)
                {
                    char ch = s[j];
                    if (ch == 'L')
                    {
                        x--;
                    }
                    else if (ch == 'R')
                    {
                        x++;
                    }
                    else if (ch == 'U')
                    {
                        y--;
                    }
                    else if (ch == 'D')
                    {
                        y++;
                    }
                    if (x >= 0 && x < n && y >= 0 && y < n) count++;
                    else break;
                }
                ans[i] = count;
            }
            return ans;
        }
};