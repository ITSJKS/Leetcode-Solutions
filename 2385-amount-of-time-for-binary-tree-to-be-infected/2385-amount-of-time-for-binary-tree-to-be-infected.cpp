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
    TreeNode* find_start(TreeNode* root, int start){
        if(root == nullptr) return nullptr;
        if(root->val == start) return root;
        TreeNode* left = find_start(root->left,start);
        TreeNode* right = find_start(root->right,start);
        if(left) return left;
        if(right) return right;
        return nullptr;
    }
    void find_parents(TreeNode* root, unordered_map <TreeNode* , TreeNode*> &mp){
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top->left)  mp[top->left] = top,q.push(top->left);
            if(top->right)  mp[top->right] = top,q.push(top->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* temp = root;
        TreeNode* node = find_start(temp,start);
        // cout<<node->val<<endl;
        unordered_map <TreeNode* , TreeNode*> mp;
        find_parents(root,mp);
        unordered_map <TreeNode* , bool> vis;
        queue <TreeNode* > q;
        int time = 0;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i = 0; i <size; i++){
                auto top =q.front();
                q.pop();
                if(top->left && !vis[top->left]){
                    vis[top->left] = 1;
                    q.push(top->left);
                }
                if(top->right && !vis[top->right]){
                    vis[top->right]= 1;
                    q.push(top->right);
                }
                if(mp[top] && !vis[mp[top]] ){
                    vis[mp[top]] = 1;
                    q.push(mp[top]);
                }

            }
        }
        return time-1;
        
    }   
};