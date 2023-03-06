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
    bool isValidBST(TreeNode* root) {
        return valid(root,-1e12,1e12);
    }
    bool valid(TreeNode* root,long long mini, long long maxi){
        if(root == nullptr) return true;
        if(root->val>mini && root->val<maxi && valid(root->left,mini,root->val) && valid(root->right,root->val,maxi)) return true;
        return false;
    }
};