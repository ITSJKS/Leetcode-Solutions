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
struct Node{
    bool isBST = true;
    int sum;
    int maxi , mini;
    Node(){
        sum = 0; // maximum sum till now
        maxi = INT_MIN; // minimum value in the subtree
        mini = INT_MAX; // maximum value in the subtree
        isBST = true; // if current subtree is bst or not
    }
};
class Solution {
public:
    int ans = 0;
    Node solve(TreeNode* root){
        if(root == nullptr){
            return Node();
        }
        Node current;
        Node left = solve(root->left);
        Node right = solve(root->right);
        int val = root->val;
        if(left.isBST && right.isBST && val > left.maxi && val < right.mini){
            current.isBST = true;
            current.sum = val + left.sum + right.sum;
            current.maxi = max(val , right.maxi);
            current.mini = min(left.mini,val);
        }
        else{
            current.isBST = false;
            current.sum = max(left.sum , right.sum);
        }
        ans = max(ans,current.sum);
        return current;
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};

/*
for each node we can check it's left subtree and then it's right subtree
if either subtree is a valid subtree we will compare their value with our cur_max
so we can carry two things while traversing our tree , pair<int,int> which will contain either a binary search tree or not and sum of the subtree
*/


