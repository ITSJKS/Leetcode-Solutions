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
    long long count = 0;
    unordered_map <long long,long long> mp;
    void solve(TreeNode* root,long long sum1 , long long targetSum){
        if(root == nullptr) return;
        sum1 += root->val;
        count += mp[sum1-targetSum];
        mp[sum1]++;
        solve(root->left,sum1,targetSum);
        solve(root->right,sum1,targetSum);
        mp[sum1]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        solve(root,0,targetSum);
        return count;
    }
};