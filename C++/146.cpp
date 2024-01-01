class Node {
public:
    int val, key;
    Node *prev, *next;
    Node(int key, int val, Node* prev = NULL, Node* next = NULL) {
        this->key = key;
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> m;
    Node *head, *tail;
    int capacity, n;
    LRUCache(int capacity) {
        // using unordered_map and self-defined class
        // reference: https://leetcode.com/problems/lru-cache/solutions/45911/java-hashtable-double-linked-list-with-a-touch-of-pseudo-nodes/
        this->capacity = capacity;
        this->n = 0;
        this->head = new Node(-1, -1);
        this->tail = new Node(-2, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }
    
    void append(Node* node){
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        return;
    }

    void moveToTail(Node* node){
        remove(node);
        append(node);
        return;
    }

    Node* popHead(){
        Node *popNode = head->next;
        remove(popNode);
        return popNode;
    }
    
    int get(int key) {
        if(m.count(key) > 0){
            int val = m[key]->val;
            moveToTail(m[key]);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key) > 0){
            m[key]->val = value;
            moveToTail(m[key]);
        }
        else{
            Node *newNode = new Node(key, value);
            append(newNode);
            m[key] = newNode;
            if(n < capacity)
                n++;
            else
                m.erase(popHead()->key);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */