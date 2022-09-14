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
    int count = 0;
    unordered_map <int,int> mp;
public:
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        mp[root->val]++;
        if(!root->left && !root->right){
            int od1=0,c=0;
            for(auto x:mp){
                c++;
                // cout<<x.first<<" "<<x.second<<endl;
                if(x.second%2 && c) od1++;
            }
            if(od1<=1) count++;
        }
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        mp.clear();
        dfs(root);
        return count;
    }
};