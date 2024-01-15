struct Node {
    Node* links[2];
    int frequency; 
    Node() : frequency(0) {
        links[0] = links[1] = NULL;
    }

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->frequency++;
        }
    }

    int getMax(int num) {
        Node* node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit) && node->get(1 - bit)->frequency > 0) {
                res = res | (1 << i);
                node = node->get(1 - bit);
            } else {
                if(node->containsKey(bit) && node->get(bit)->frequency > 0) node = node->get(bit);
                else return 0;
            }
        }
        return res;
    }

    void deleteKey(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(bit)) {
                node = node->get(bit);
                node->frequency--;
            } else {
                break;
            }
        }
    }
};
class Solution {
public:
    vector <int> ans;
    unordered_map <int,vector<pair<int,int>>> mp;
    void dfs(int src, int par, vector <vector <int>>&g,  Trie& trie){
        trie.insert(src);
        for(auto &node:mp[src]){
            ans[node.second] = trie.getMax(node.first);
        }
        for(auto &nbr:g[src]){
            if(nbr == par) continue;
            dfs(nbr,src,g,trie);
        }
        trie.deleteKey(src);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int q = queries.size();
        for(int i = 0; i <queries.size(); i++){
            int node = queries[i][0];
            int val =queries[i][1];
            mp[node].push_back({val,i});
        }
        int root;
        int n = parents.size();
        vector <vector <int>> g(n);
        for(int i = 0; i <parents.size(); i++){
            if(parents[i] == -1) root = i;
            else{
                g[i].push_back(parents[i]);
                g[parents[i]].push_back(i);
            }
        }
        Trie trie;
        ans.resize(q);
        dfs(root,-1,g,trie);
        return ans;
    }
};

// how does xor work
// I can just store the number of bit's between 