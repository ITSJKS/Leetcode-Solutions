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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
           vector <int> parent(1005);
        parent[root->val] = -1;
        queue <TreeNode*> q;
        q.push(root);
        vector <int> deep;
        unordered_map <int,TreeNode*> mp;
        while(!q.empty()){
            int size = q.size();
            bool check = true;
            for(int i = 0; i <size; i++){
                auto node = q.front();
                mp[node->val] = node;
                q.pop();
                deep.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                    check = false;
                    parent[node->left->val] = node->val;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right->val] = node->val;
                    check = false;
                }
                
            }
            if(!check){
                deep = {};
            }
        }
        // for(auto x:deep){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        if(deep.size() == 1){
            return mp[deep[0]];
        }
        else{
            queue <int> q1;
            for(auto x:deep){
                q1.push(x);
            }
            while(!q1.empty()){
                set <int> st;
                int size = q1.size();
                for(int i = 0; i <size; i++){
                    int node = q1.front();
                    q1.pop();
                    st.insert(parent[node]);
                }
                if(st.size() == 1) return mp[*st.begin()];
                else{
                    for(auto x:st){
                        q1.push(x);
                    }
                }
            }
        }
        return nullptr;
    }
};