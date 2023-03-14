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
    vector <int> a;
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        if(root->left) dfs(root->left);
        a.push_back(root->val);
        if(root->right) dfs(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector <vector <int>> ans;
        dfs(root);
        for(auto x:queries){
            auto it = lower_bound(a.begin(),a.end(),x) - a.begin();
            int n = a.size();
            if(it == n){
                ans.push_back({a[it-1],-1});
            }
            else if(it == 0){
                if(a[it] == x){
                    ans.push_back({x,x});
                }
                else{
                    ans.push_back({-1,a[it]});
                }
            }
            else{
                if(a[it] == x){
                    ans.push_back({x,x});
                }
                else{
                    ans.push_back({a[it-1],a[it]});
                }
            }
        }
        return ans;
        
    }
};