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
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        find_sum(root,low,high);
        return sum;
    }
    int find_sum(TreeNode* root , int low, int high){
        if(root==NULL) return 0;
        find_sum(root->left,low,high);
        if(root->val >=low && root->val <= high) sum += root->val;
        find_sum(root->right,low,high);
        return sum;
    }
};