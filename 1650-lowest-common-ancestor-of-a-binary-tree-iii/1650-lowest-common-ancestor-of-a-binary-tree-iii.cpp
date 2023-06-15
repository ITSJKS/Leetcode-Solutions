/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map <Node* , int> mp;
        while(p!=nullptr){
            mp[p] = 1;
            p = p->parent;
        }
        while(q!=nullptr){
            if(mp[q]) return q;
            q = q->parent;
        }
        return q;
    }
};