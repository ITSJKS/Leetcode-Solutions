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
    vector <vector <int> > paths;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> path;
        dfs(root,targetSum,path);
        return paths;
    }
    int dfs(TreeNode* root, int targetSum,vector <int> &path){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val){
                path.push_back(root->val);
                paths.push_back(path);
                path.pop_back();
                return 1;
            }
            else{
                return 0;
            }
        }
        path.push_back(root->val);
        dfs(root->left,targetSum - root->val,path);
        dfs(root->right,targetSum - root->val,path);
        path.pop_back();
        return 1;
    }
};