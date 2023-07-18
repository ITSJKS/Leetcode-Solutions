
class LRUCache {

public:
class Node {
    public:
    int key;
    int val;
    Node* prev,* next;
    public:
    Node(int k, int v){
        key = k,val = v;
    }
};
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
 
    unordered_map <int,Node*> lru;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev =head;
    }
    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNode(Node* node){
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev  = head;
    }
    int get(int key) {
        if(lru.find(key)!=lru.end()){
            Node* node = lru[key];
            int val = node->val;
        lru.erase(key);
        deleteNode(node);
        addNode(node);
        lru[key ] = head->next;
        return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lru.find(key) != lru.end()){
            Node* node = lru[key];
            lru.erase(key);
            deleteNode(node);
        }
        if(lru.size()==cap){
            lru.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        lru[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */