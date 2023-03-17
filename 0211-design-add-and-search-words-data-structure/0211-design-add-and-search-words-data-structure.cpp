struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
};
class Trie
{
    private: Node * root;
    public: /**Initialize your data structure here. */ Trie()
    {
        root = new Node();
    } /**Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    bool search_word(string word){
        return search(root,word);
    }
    bool search(Node* node, string word){
        int i = 0; 
        for(auto x:word){
            if(x == '.'){
                for(char ch = 'a'; ch<='z'; ch++){
                    if(node->containsKey(ch)){
                        if(search(node->get(ch),word.substr(i+1))) return true;
                    }
                }
                return false;
            }
            else{
                if(!node->containsKey(x)) return false;
                node = node->get(x);
            }
        i++;
        }
        if(node->getEnd()) return true;
        return false;
    }
};
class WordDictionary {
public:
    Trie trie;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search_word(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */