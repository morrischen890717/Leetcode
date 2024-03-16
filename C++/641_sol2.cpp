class Node {
public:
    int val;
    Node *prev, *next;
    Node(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};
class MyCircularDeque {
private:
    int k;
    Node *head;
public:
    MyCircularDeque(int k) {
        this->k = k;
        this->head = NULL;
    }
    
    bool insertFront(int value) {
        if(k <= 0)
            return false;
        Node *newNode = new Node(value);
        if(head){
            head->prev->next = newNode;
            newNode->prev = head->prev;
            head->prev = newNode;
            newNode->next = head;
        }
        else{
            newNode->prev = newNode;
            newNode->next = newNode;
        }
        head = newNode;
        k--;
        return true;
    }
    
    bool insertLast(int value) {
        if(k <= 0)
            return false;
        Node *newNode = new Node(value);
        if(head){
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
        }
        else{
            head = newNode;
            head->prev = head;
            head->next = head;
        }
        k--;
        return true;
    }
    
    bool deleteFront() {
        if(!head)
            return false;
        if(head->prev == head)
            head = NULL;
        else{
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }
        k++;
        return true;
    }
    
    bool deleteLast() {
        if(!head)
            return false;
        if(head->prev == head)
            head = NULL;
        else{
            head->prev->prev->next = head;
            head->prev = head->prev->prev;
        }
        k++;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : head->val;
    }
    
    int getRear() {
        return isEmpty() ? -1 : head->prev->val;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    bool isFull() {
        return k <= 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */