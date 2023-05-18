/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* recoverFromPreorder(string s)
        {
            unordered_map<int, TreeNode*> mp;
            int n = s.size();
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '-') count++;
                else
                {
                    string temp;
                    while (i < n && s[i] != '-')
                    {
                        temp.push_back(s[i]);
                        i++;
                    }
                    i--;
                    int num = stoi(temp);
                    TreeNode *node = new TreeNode(num);
                    mp[count] = node;
                    if (count)
                    {
                        if (mp[count - 1]->left) mp[count-1]->right = node;
                        else mp[count-1]->left = node;
                    }
                    count = 0;
                }
            }
            return mp[0];
        }
};