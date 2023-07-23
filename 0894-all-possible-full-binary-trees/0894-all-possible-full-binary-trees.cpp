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
    unordered_map <int,vector <TreeNode*>> mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n&1 == 0) return {};
        if(n==1) return {new TreeNode()};
        if(mp.find(n)!=mp.end()) return mp[n];
        vector <TreeNode*> ans;
        for(int i = 1; i <n; i+=2){
        vector <TreeNode*> left_nodes = allPossibleFBT(i);
        vector <TreeNode*> right_nodes = allPossibleFBT(n-i-1);
        for(auto &l:left_nodes){
            for(auto &r:right_nodes){
                TreeNode* root = new TreeNode(0);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
        }
        return mp[n] = ans;
    }
};