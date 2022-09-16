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
    vector <string> paths;
    string path;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return paths;
    }
    void dfs(TreeNode* root){
        if(root==NULL){
            paths.push_back(path);
           return;
        }
        string temp = path;
        if(root->left || root->right){
            path += to_string(root->val) + "->";
            if(root->left) dfs(root->left);
            if(root->right) dfs(root->right);
        }
        else{
            
            path += to_string(root->val);
            paths.push_back(path);
        }
         path = temp;
            
    
    }
};