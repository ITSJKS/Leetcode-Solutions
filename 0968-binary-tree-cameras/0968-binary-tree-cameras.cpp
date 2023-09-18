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
    int count = 0;
    int solve(TreeNode*root){
        if(root == nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if(left ==  -1 || right ==  -1){
            count++;
            return 1;
        }
        if(left == 1 || right == 1){
            return 0;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1) count++;
        return count;
    }
};