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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* root1 = new TreeNode(val);
            root1->left = root;
            return root1;
        }
        dfs(root,val,1,depth);
        return root;
    }
    void dfs(TreeNode* root,int val, int d, int depth){
        if(root == NULL) return;
        if(d < depth-1){
            dfs(root->left,val,d+1,depth);
            dfs(root->right,val,d+1,depth);
        }
        else{
            TreeNode* l_node = (root->left);
            TreeNode* r_node = root->right;
            TreeNode* new_node1 = new TreeNode(val);
            TreeNode* new_node2 = new TreeNode(val);
            root->left = new_node1;
            root->right = new_node2;
            new_node1->left  = l_node;
            new_node2->right = r_node;
        }
        
    }
};