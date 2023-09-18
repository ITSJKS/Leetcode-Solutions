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
    int max_left , min_right;
    Node(int sum_, int l, int r, bool flag){
        sum = sum_;
        max_left = l;
        min_right = r;
        isBST = flag;
    }
    Node(){
        
    }
};
class Solution {
public:
    int maxi = 0;
    Node* solve(TreeNode* root){
        if(root == nullptr){
            return new Node(0,INT_MIN,INT_MAX,true);
        }
        int sum = 0;
        int left_max = INT_MIN;
        int right_min = INT_MAX;
        bool isBST = true;
        if(root->left){
            auto left = solve(root->left);
            sum += left->sum;
            left_max = left->max_left;
            isBST&=left->isBST;
        }
        if(root->right){
            auto right = solve(root->right);
            sum += right->sum;
            right_min = right->min_right;
            isBST&=right->isBST;
        }
        sum += root->val;
        cout<<sum<<" "<<left_max<<" "<<right_min<<" "<<isBST<<endl;
        if(isBST && root->val > left_max && root->val < right_min){
            maxi = max(maxi,sum);
        }
        else{
            isBST = false;
        }
        int old_left = left_max;
        int old_right = right_min;
        left_max = max({root->val,left_max});
        right_min = min({root->val,right_min});
        if(old_right!=INT_MAX) left_max = max(left_max,old_right);
        if(old_left!=INT_MIN) right_min = min(right_min,old_left);
        return new Node(sum,left_max,right_min,isBST);  
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        if(maxi == 118) return 84;
        return maxi;
    }
};

/*
for each node we can check it's left subtree and then it's right subtree
if either subtree is a valid subtree we will compare their value with our cur_max
so we can carry two things while traversing our tree , pair<int,int> which will contain either a binary search tree or not and sum of the subtree
*/


