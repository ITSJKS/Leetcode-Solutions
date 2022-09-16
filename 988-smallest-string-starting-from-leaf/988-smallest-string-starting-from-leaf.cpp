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
    vector <string> all_paths;
    string temp;
    
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        // for(auto x:all_paths){
        //     cout<<x<<endl;
        // }
        sort(all_paths.begin(),all_paths.end());
        string ans = all_paths[0];
        return ans;
    }
    void dfs(TreeNode* root){
        if(root==NULL) return;
        if(root->left || root->right){
            temp.push_back(root->val + 'a');
            if(root->left){
                dfs(root->left);
            }
            if(root->right)
                dfs(root->right);
            temp.pop_back();
        }
        else if(!root->left && !root->right){
            temp.push_back(root->val + 'a');
            string temp1 = temp;
            reverse(temp1.begin(),temp1.end());
            all_paths.push_back(temp1);
            temp.pop_back();
        }

        
    }
};