/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mx = 0;
    unordered_map <int,int> mp;
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        mp[root->val]++;
        mx = max(mx,mp[root->val]);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector <int> v;
        for(auto &x:mp) if(x.second == mx) v.push_back(x.first);
        return v;
    }
};