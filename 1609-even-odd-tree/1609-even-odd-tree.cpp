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
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr) return true;
        bool turn = true;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool check = true;
            int prev = -1;
            for(int j = 0;j <size; j++){
                auto node = q.front();
                if(node->left)q.push(node->left);
                if(node->right) q.push(node->right);
                int node_val = node->val;
                q.pop();
                if(prev != -1){
                    if(turn){
                        if((node_val&1) && (node_val > prev)){
                            
                        }
                        else return false;
                    }
                    else{
                        if((node_val%2 == 0) && (node_val < prev)){
                            
                        }
                        else return false;
                    }
                }
                else{
                    if((node_val%2) != (turn)) return false;
                }
                prev = node_val; 
            }
            turn = !turn;
        }
        return true;
    }
};