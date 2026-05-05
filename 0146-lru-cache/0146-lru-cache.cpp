class DLL {
public:
    int key, value;
    DLL* next;
    DLL* prev;
    DLL(){
        key = -1;
        value = -1;
        next = NULL;
        prev = NULL;
    }
    DLL(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
private:
    void insertAfterHead(DLL* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void deleteNode(DLL* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    unordered_map<int, DLL*> mp;
    DLL* head;
    DLL* tail;
    int size;
    LRUCache(int capacity) {
        size = capacity;
        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        DLL* node = mp[key];
        int val = node->value;
        deleteNode(node);
        insertAfterHead(node);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() == size){
                DLL* delnode = tail->prev;
                mp.erase(delnode->key);
                deleteNode(delnode);
                delete delnode;
            }
            DLL* node = new DLL(key, value);
            insertAfterHead(node);
            mp[key] = node;
        }
        else{
            DLL* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */