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
    bool isCompleteTree(TreeNode* root1) {
        queue <TreeNode*> q;
        q.push(root1);
        int p = 1;
        bool is_left = false;
        bool is_last = false;
        while(!q.empty()){
            int size = q.size();
            if(size!=p){
                is_last = true;
            }
            p*=2;
            for(int i = 0; i <size; i++){
                auto root = q.front();
                q.pop();
                if(root->left){
                    if(is_left || is_last) return false;
                    q.push(root->left);
                }
                else is_left = true;
                if(root->right){
                    if(is_left || is_last) return false;
                    q.push(root->right);
                }
                else is_left = true; 
            }
        }
        return true;
    }
};