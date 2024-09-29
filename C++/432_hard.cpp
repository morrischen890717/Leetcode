class Node {
public:
    string s;
    int cnt;
    Node *prev, *next;
    Node(string s){
        this->s = s;
        cnt = 1;
        prev = next = NULL;
    }
};
class AllOne {
public:
    unordered_map<string, Node*> m;
    Node *head, *tail;
    AllOne() {
        head = new Node("");
        tail = new Node("");
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(!m.count(key)){
            m[key] = new Node(key);
            head->next->prev = m[key];
            m[key]->next = head->next;
            m[key]->prev = head;
            head->next = m[key];
            return;
        }
        else{
            m[key]->cnt++;
            Node *ptr = m[key]->next;
            while(ptr != tail && m[key]->cnt > ptr->cnt){
                ptr = ptr->next;
            }
            m[key]->prev->next = m[key]->next;
            m[key]->next->prev = m[key]->prev;
            ptr->prev->next = m[key];
            m[key]->prev = ptr->prev;
            ptr->prev = m[key];
            m[key]->next = ptr;
        }
        return;
    }
    
    void dec(string key) {
        m[key]->cnt--;
        if(m[key]->cnt == 0){
            m[key]->prev->next = m[key]->next;
            m[key]->next->prev = m[key]->prev;
            m.erase(key);
            return;
        }
        else{
            Node *ptr = m[key]->prev;
            while(ptr != head && m[key]->cnt < ptr->cnt){
                ptr = ptr->prev;
            }
            m[key]->prev->next = m[key]->next;
            m[key]->next->prev = m[key]->prev;
            ptr->next->prev = m[key];
            m[key]->next = ptr->next;
            m[key]->prev = ptr;
            ptr->next = m[key];
        }
        return;
    }
    
    string getMaxKey() {
        return head->next == tail ? "" : tail->prev->s;
    }
    
    string getMinKey() {
        return head->next == tail ? "" : head->next->s;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */