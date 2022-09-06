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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;
        if(count_one(root) == 0) return nullptr;
        return root;
    }
    int count_one(TreeNode* root){
        if(root == NULL) return 0;
        int left = count_one(root->left);
        if(left == 0) root->left = nullptr;
        int right = count_one(root->right);
        if(right == 0) root->right = nullptr;
        // cout<<left <<" "<<right<<" "<<root->val<<endl;
        return left + right + root->val;
    }
};