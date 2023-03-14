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
    int sumNumbers(TreeNode* root) {
        long long ans = 0;
        queue <pair <TreeNode* , long long >> q;
        q.push({root,root->val});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i <size; i++){
                TreeNode* node = q.front().first;
                long long prev = q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left,prev*10 + node->left->val});
                }
                if(node->right){
                    q.push({node->right,prev*10 + node->right->val});
                }
                if(node->left == nullptr && node->right == nullptr){
                    ans += prev;
                }
            }
        }
        return ans;
        
    }
};