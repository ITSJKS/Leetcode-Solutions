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
    int mini = INT_MAX;
    void dfs(TreeNode* root, int &prev){
        if(root == nullptr) return;
        dfs(root->left,prev);
        if(prev == -1){
            prev = root->val;
        }
        else{
            mini = min(mini,root->val -prev);
            prev = root->val;
        }
        dfs(root->right,prev);
        
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        dfs(root,prev);
        return mini;
    }
};