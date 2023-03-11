/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector <int> v;
public:
    TreeNode* binary_search_tree(int low, int high){
        if(low > high) return NULL;
        int mid = low + (high-low)/2;
        TreeNode* temp = new TreeNode(v[mid]);
        temp->left = binary_search_tree(low,mid-1);
        temp->right = binary_search_tree(mid+1,high);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        return binary_search_tree(0,v.size()-1);
    }
};