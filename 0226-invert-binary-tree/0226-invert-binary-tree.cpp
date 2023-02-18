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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        invert(root->left,root->right);
        return root;
        }
    
    void invert(TreeNode* &root1, TreeNode* &root2){
        if(root1&&root2) {
            swap(root1->val,root2->val);
            invert(root1->left,root2->right);
            invert(root1->right,root2->left);
        }
        else if(root1){
            root2= root1;
            root1 = NULL;
            if(root2)
            invert(root2->left,root2->right);
        }
        else if(root2){
            root1 = root2;
            root2 = NULL;
            if(root1)
            invert(root1->left,root1->right);
        }
    }
};