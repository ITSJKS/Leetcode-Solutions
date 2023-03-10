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
        vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode* root, unordered_map <int,int> &mp,bool isFirst){
        if(root == nullptr) return nullptr;
        bool check = mp.count(root->val);
        if(!check && isFirst) ans.push_back(root);
        root->left = dfs(root->left,mp,check);
        root->right = dfs(root->right,mp,check);
        return check?nullptr:root;
    }
    vector<TreeNode*> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        int n = to_delete.size();
        unordered_map <int,int> mp;
        for(auto x:to_delete) mp[x]++;
        dfs(root,mp,1);
        return ans;
    }
};