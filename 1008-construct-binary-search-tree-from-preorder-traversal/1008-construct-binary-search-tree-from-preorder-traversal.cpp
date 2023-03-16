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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector <int> &a, int &i, int bound){
        if(i == a.size() || a[i] > bound) return nullptr;
        TreeNode * root =new TreeNode(a[i++]);
        root->left = build(a,i,root->val);
        root->right = build(a,i,bound);
        return root;
    }
};

// everything in left is lesser than root->Val and everything on right is less than bound at the root
// so we can construct the tree using just one bound
// recursively build left and right of the root using the bound