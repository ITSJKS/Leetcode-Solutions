struct Node
{
    Node *links[26];
    bool is_end = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node* get(char ch)
    {
        return (links[ch - 'a']);
    }
    void put(char ch, Node *node)
    {
        links[ch-'a'] = node;
    }
    void setEnd()
    {
        is_end = true;
    }
    bool isEnd()
    {
        return is_end;
    }
};
class Trie
{
    public:
        Node * root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (auto x: word)
        {
            if (!node->containsKey(x))
            {
                Node *child = new Node();
                node->put(x, child);
            }
            node = node->get(x);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (auto x: word)
        {
            if (!node->containsKey(x)) return false;
            node = node->get(x);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (auto x: prefix)
        {
            if (!node->containsKey(x)) return false;
            node = node->get(x);
        }
        return true;
    }
};

/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */