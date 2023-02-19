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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode* > q;
        vector <vector <int>> res;
        if(root)
        q.push(root);
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            vector <TreeNode*> temp;
            vector <int> temp1;
            for(int i = 0; i <size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(count%2){
                    temp1.push_back(node->val);
                if(node->left)
                temp.push_back(node->left);
                if(node->right)
                temp.push_back(node->right);
                }
                else{
                    if(node->right)
                temp.push_back(node->right);
                    temp1.push_back(node->val);
                if(node->left)
                temp.push_back(node->left);
                
                }
                
            }
            res.push_back(temp1);
            reverse(temp.begin(),temp.end());
            for(auto x:temp){
                q.push(x);
            }
            count++;
        }
        return res;
    }
};