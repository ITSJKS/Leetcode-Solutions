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
    TreeNode* lca(TreeNode* root,TreeNode* a, TreeNode* b){
        if(root == a || root == b || root == nullptr) return root;
        TreeNode* left = lca(root->left,a,b);
        TreeNode* right = lca(root->right,a,b);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        TreeNode* p = nodes[0];
        for(int i = 1; i <nodes.size(); i++){
            p = lca(root,p,nodes[i]);
        }
        return p;
    }
};
// different way to solve this problem, we can find lca of two nodes then we can find lca of cur_lca node with next node and so on
// how to find lca of two node
// we can start traversing from root , if both the node can be find in the same same side our lca will be in that side else cur_node will be our lca

//2nd approach 
// we can start from root and traverse both left and right , at any point if the number of nodes in the nodes array are in same side of our root, we will find our lca in that side ,else our cur_node is the lca