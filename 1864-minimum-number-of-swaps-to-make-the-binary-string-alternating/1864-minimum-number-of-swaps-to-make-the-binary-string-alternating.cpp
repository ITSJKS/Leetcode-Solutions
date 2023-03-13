class Solution
{
    public:
        int minSwaps(string s)
        {
            int n = s.size();
            int ones = 0;
            int odd_1 = 0, even_1 = 0;
            for (int i = 0; i < n; i++)
            {
                char ch = s[i];
                ones += (ch == '1');
            }
            int zeroes = n - ones;
            if (n % 2 && abs(ones - zeroes) > 1) return -1;
            else if (n % 2 == 0 && ones != zeroes) return -1;
           	// now two case
           	// Fixing 1 in first pos
            if (n % 2 == 0)
            {
                int count1 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (i % 2 == 0)
                    {
                        if (s[i] != '1') count1++;
                    }
                    else
                    {
                        if (s[i] != '0') count1++;
                    }
                }
                count1 /= 2;
                int count2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (i % 2 == 0)
                    {
                        if (s[i] != '0') count2++;
                    }
                    else
                    {
                        if (s[i] != '1') count2++;
                    }
                }
                count2 /= 2;
                return min(count1, count2);
            }
            else
            {
                if (ones > zeroes)
                {
                    int count1 = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if (i % 2 == 0)
                        {
                            if (s[i] != '1') count1++;
                        }
                        else
                        {
                            if (s[i] != '0') count1++;
                        }
                    }
                    count1 /= 2;
                    return count1;
                }
                else
                {
                    int count2 = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if (i % 2 == 0)
                        {
                            if (s[i] != '0') count2++;
                        }
                        else
                        {
                            if (s[i] != '1') count2++;
                        }
                    }
                    return count2/2;
                }

               	// fixing 0 in first pos
            }
            return 0;
        }
        };