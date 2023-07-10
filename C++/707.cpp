class MyLinkedList {
private:
    class LinkedListNode{
    public:
        int val;
        LinkedListNode *next;
        LinkedListNode(int val, LinkedListNode* next = NULL){
            this->val = val;
            this->next = next;
        }
    };

public:
    int len;
    LinkedListNode *head, *tail;
    MyLinkedList() {
        len = 0;
        head = tail = NULL;
    }
    
    int get(int index) {
        if(index >= len)
            return -1;
        LinkedListNode *cur = head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedListNode *newHead = new LinkedListNode(val, head);
        head = newHead;
        if(len == 0)
            tail = head;
        len++;
        return;
    }
    
    void addAtTail(int val) {
        LinkedListNode *newTail = new LinkedListNode(val, NULL);
        if(tail)
            tail->next = newTail;
        tail = newTail;
        if(len == 0)
            head = tail;
        len++;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if(index > len)
            return;
        else if(index == 0){
            addAtHead(val);
            return;
        }
        else if(index == len){
            addAtTail(val);
            return;
        }
        else{
            LinkedListNode *cur = head, *prev;
            for(int i = 0; i < index; i++){
                prev = cur;
                cur = cur->next;
            }
            LinkedListNode *newNode = new LinkedListNode(val, cur);
            prev->next = newNode;
            len++;
        }
        return;
    }
    
    void deleteAtIndex(int index) {
        if(index >= len)
            return;
        LinkedListNode *cur = head, *prev = head;
        for(int i = 0; i < index; i++){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        if(cur == head)
            head = head->next;
        if(cur == tail)
            tail = prev;
        delete cur;
        len--;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */