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
    map <pair<TreeNode*,int>,int> mp;
    int func(TreeNode* node, int opt) {
        if(node == nullptr) return 0;
        if(mp.count({node,opt})) return mp[{node,opt}];
        
        if(opt == 1)
            return mp[{node, opt}] = 1 + func(node->left, 2) + func(node->right, 2);
        
        if(opt == 2)
        {
            int cam = 1 + func(node->left, 2) + func(node->right, 2);
            int nocam = func(node->left, 3) + func(node->right, 3);
            return mp[{node, opt}] = min(cam, nocam);
        }
        
        else
        {
            int cam = 1 + func(node->left, 2) + func(node->right, 2);
            int leftcam = INT_MAX, rightcam = INT_MAX;
            
            if(node->left)
                leftcam = func(node->left, 1) + func(node->right, 3);
            
            if(node->right)
                rightcam = func(node->left, 3) + func(node->right, 1);
            
            
            return mp[{node, opt}] = min(min(cam, leftcam), rightcam);
        }
        
    }
    int minCameraCover(TreeNode* root) {
        if(root == nullptr) return 0;
        return func(root,3);
    }
};

/*
It is kind of similar to the problem I saw few days ago
we can apply dp here
when for a node , we keep a camera , we will 



*/