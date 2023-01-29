struct Node{
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    void addFront(Node* node){
        Node* temp = head->next;
         node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node){
        Node* temp = node->prev;
        Node* temp_next = node->next;
        temp->next = temp_next;
        temp_next->prev = temp;
        size--;
    }
    
};
class LFUCache {
public:
    map <int,List*> freqListMap;
    map <int,Node*> keyNode;
    int cap;
    int minFreq;
    int curSize;
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        List* next_higher = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            next_higher = freqListMap[node->cnt+1];
        }
        node->cnt += 1;
        next_higher->addFront(node);
        freqListMap[node->cnt] = next_higher;
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{
            if(curSize == cap){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */