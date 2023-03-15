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
        bool isCompleteTree(TreeNode *root1)
        {
            queue<TreeNode*> q;
            q.push(root1);
            bool is_last = false;
            while (!q.empty())
            {
                auto root = q.front();
                q.pop();
                if(root == nullptr) is_last = true;
                else{
                    if(is_last) return false;
                    q.push(root->left);
                    q.push(root->right);
                }
            }
            return true;
        }
};