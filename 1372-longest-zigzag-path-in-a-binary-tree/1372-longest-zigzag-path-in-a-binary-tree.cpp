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
    int ans = 0;
    void solve(TreeNode* root, bool turn, int step){
        if(root == nullptr) return;
        ans = max(ans,step);
        if(turn == 1){
            solve(root->left,0,step+1);
            solve(root->right,1,1);
        }
        if(turn == 0){
            solve(root->right,1,step+1);
            solve(root->left,0,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root,1,0);
        solve(root,0,0);
        return ans;
    }
};